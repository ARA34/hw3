#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
#include <vector>
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename) {
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if(!(ifile >> v)) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while (ifile >> v) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void dealloc(Node* head) {
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------
Node* makeList(std::vector<int> const & content) {
	Node* head = nullptr;
	Node* tail = nullptr;

	for(auto v : content) {
		if(head == nullptr) {
			head = new Node(v,nullptr);
			tail = head;
		}
		else {
			tail->next = new Node(v,nullptr);
			tail = tail->next;
		}
	}
	return head;
}

struct IsOdd {
  bool operator()(int num) {
    return (num % 2) != 0;
  }
};

int main(int argc, char* argv[]) {
  // if(argc < 2) {
  //     std::cout << "Please provide an input file" << std::endl;
  //     return 1;
  // }

  // -----------------------------------------------
  // Feel free to update any code below this point
  // -----------------------------------------------
  // Node* head = readList(argv[1]);
  // std::cout << "Original list: ";
  // print(head);


  // ############# Test out llpivot #############
  // Node* head = makeList({2,4,8,3});
  // std::cout << "Original list: ";
  // print(head);
  // Node* smaller = NULL;
  // Node* larger = NULL;
  // llpivot(head, smaller, larger, 5);
  // std::cout << "After llpivot" << std::endl;
  // print(head);
  // std::cout << "smaller" << std::endl;
  // print(smaller);
  // std::cout << "larger" << std::endl;
  // print(larger);

  /*
  llpivot OUTPUT (10/12):
  Original list: 2 4 8 3 
  After llpivot

  smaller
  2 4 3 
  larger
  8 
  */

  // ############# Test out llfilter #############
  Node* head = makeList({3, 6, 4, 9});
  std::cout << "Original list: ";
  print(head);

  Node* filtered = llfilter(head, IsOdd());
  std::cout << "after filtering" << std::endl;
  print(filtered);




  
  return 0;
}
