#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    if (head == nullptr) {
        if (smaller != nullptr) {
            smaller = nullptr;
        }
        if (larger != nullptr) {
            larger = nullptr;
        }
        return;
    }
    else {
        if (head->val <= pivot) {
            smaller = head;
            head = head->next;
            llpivot(head, smaller->next, larger, pivot);
        }
        else {
            larger = head;
            head = head->next;
            llpivot(head, smaller, larger->next, pivot);
        }
    }
}