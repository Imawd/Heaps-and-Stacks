#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
	if (head == NULL) {
		//returns both lists as empty
		smaller = NULL;
		larger = NULL;
		return;
	}

	else {
		//if value of item is smaller than or equal to pivot
		//add it to smaller LL and recursive call the next element in the list
		if (head->val <=  pivot) {
			smaller = head;
			head = head->next;
			llpivot(head, smaller->next, larger, pivot);
		}
		//if value of item is larger than pivot
		//add to larger list and recursive call rest of elements
		else if (head->val > pivot) {
			larger = head;
			head = head->next;
			llpivot(head, smaller, larger->next, pivot);
		}
	}
}

//operator () returns true if odd (i.e. returns true if it is to be filtered)
bool Comp::operator()(int x) {
	//is this element supposed to be filtered?
	if (x % 2 == 0) return false; //no
	else return true; //yes
}


