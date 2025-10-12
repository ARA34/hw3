#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
  if (head == NULL) {
    return; //basecase
  } else {
    return llpivot(head->next);

    // this will execute in backwards order: [3, 8, 4, 2]
    Node* popped = head;
    head = head->next;
    if (*popped > pivot) {
      // push to larger linked list
      if (!larger) {
        larger = popped;
      } else {
        Node* temp = larger;
        larger = popped;
        larger->next = temp;
      }
    } else if (*popped <= pivot) {
      // push to smaller
      if (!smaller) {
        smaller = popped;
      } else {
        Node* temp = smaller;
        smaller = popped;
        smaller->next = temp;
      }
    }
  }
}



