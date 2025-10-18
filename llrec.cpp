#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
  if (!(head)) {
    smaller = nullptr;
    larger = nullptr;
    return; //basecase
  } else {
    Node* popped = head;
    head = head->next;

    llpivot(head, smaller, larger, pivot);

    popped->next = nullptr;

    // this will execute in backwards order: [3, 8, 4, 2]
    if ((*popped).val > pivot) {
      // push to larger linked list
      if (!(larger)) {
        larger = popped;
      } else {
        Node* temp = larger;
        larger = popped;
        larger->next = temp;
        temp = nullptr;
      }
    } else if ((*popped).val <= pivot) {
      // push to smaller
      if (!smaller) {
        smaller = popped;
      } else {
        Node* temp = smaller;
        smaller = popped;
        smaller->next = temp;
        temp = nullptr;
      }
    }
  }
}



