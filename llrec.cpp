#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
//smaller, larger, and head are all pointers to classes. 

  //what would base case be? 
  if(head == NULL){ //this represents an empty list
    smaller = NULL;
    larger = NULL;
    return; 
  }

  if(head->val > pivot){ //if the value head is pointing to is greater than pivot
      larger = head; //larger pointer now pointing to where head is pointing to 
      
      Node* newhead = head->next; //create a new head node, where we point to the next node with our head
      head = NULL;  //current head now set to empty
      llpivot(newhead, smaller, larger->next, pivot); //now, larger is a pointer to next node to check
      
      //head = NULL;
//now, we are calling a function where we have the head and larger pointer to point to a new node

  } 
  else if(head->val <= pivot){ //if the value head is pointing to is less than pivot
      //  larger = head; //larger is now pointing to where NODE head is pointing to
      //  Node *newhead = head -> next; 
      smaller = head; //set 
      Node* newhead = head->next;
      head = NULL; 
      llpivot(newhead, smaller->next, larger, pivot);
  }

}

/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value

*/