#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <cmath>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
    /**
     * @brief Construct a new Heap object
     *
     * @param m ary-ness of heap tree (default to 2)
     * @param c binary predicate function/functor that takes two items
     *          as an argument and returns a bool if the first argument has
     *          priority over the second.
     */
    Heap(int m = 2, PComparator c = PComparator());

    /**
    * @brief Destroy the Heap object
    *
    */
    ~Heap();

    /**
     * @brief Push an item to the heap
     *
     * @param item item to heap
     */
    void push(const T& item);

    /**
     * @brief Returns the top (priority) item
     *
     * @return T const& top priority item
     * @throw std::underflow_error if the heap is empty
     */
    T const& top() const;

    /**
     * @brief Remove the top priority item
     *
     * @throw std::underflow_error if the heap is empty
     */
    void pop();

    /// returns true if the heap is empty

    /**
     * @brief Returns true if the heap is empty
     *
     */
    bool empty() const;

    /**
   * @brief Returns size of the heap
   *
   */
    size_t size() const;

private:
    /// Add whatever helper functions and data members you need below
    std::vector<T> _data;
    int m;
    PComparator pc;
    void Heapify();
    void Heapify(int index);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
    :m(m), pc(c)
{
    
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
    _data.push_back(item);
    Heapify();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const& Heap<T, PComparator>::top() const
{
    // Here we use exceptions to handle the case of trying
    // to access the top element of an empty heap
    if (empty()) {
        // ================================
        // throw the appropriate exception
        // ================================
        throw std::underflow_error("Underflow Error");

    }
    // If we get here we know the heap has at least 1 item
    // Add code to return the top element
    return _data[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
    if (empty()) {
        // ================================
        // throw the appropriate exception
        // ================================
        throw std::underflow_error("Underflow Error");
    }
    _data[0] = _data[_data.size() - 1];
    _data.pop_back();
    Heapify();
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return _data.size() == 0;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return _data.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::Heapify() {
    int lastNonLeaf = (int)floor(_data.size() / 2) - 1;

    for (int i = lastNonLeaf; i >= 0; i--) {
        Heapify(i);
    }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::Heapify(int index) {
    int lastNonLeaf = index;
    if (lastNonLeaf == -1)
        lastNonLeaf = (int)floor(_data.size() / 2) - 1;

    // heapify leaf
    int highest = lastNonLeaf;
    int _left = 2 * highest + 1;
    int _right = 2 * highest + 2;

    if (_left > (int)_data.size() - 1) {
        _left = -1;
    }
    if (_right > (int)_data.size() - 1) {
        _right = -1;
    }

    if (highest == -1) {
        return;
    }

    if (_left > -1 && !pc(_data[highest], _data[_left])) { // if highest is not "higher" than left
        // switch higher and left
        T temp = _data[highest];
        _data[highest] = _data[_left];
        _data[_left] = temp;
    }
    if (_right > -1 && !pc(_data[highest], _data[_right])) { // if highest is not "higher" than right
        // switch higher and right
        T temp = _data[highest];
        _data[highest] = _data[_right];
        _data[_right] = temp;
    }
    
    if (index != 0) {
        // if left has children, heapify left
        int left_child1 = 2 * _left + 1;
        //int left_child2 = 2 * _left + 2;
        if (_left > -1 && (int)_data.size() > left_child1) {
            Heapify(_left);
        }

        // if right has children, heapify right
        int right_child1 = 2 * _right + 1;
        //int right_child2 = 2 * _right + 2;
        if (_right > -1 && (int)_data.size() > right_child1) {
            Heapify(_right);
        }
    }
}


#endif