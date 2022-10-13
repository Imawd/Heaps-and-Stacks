#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
	if (head == NULL) {
		smaller = NULL;
		larger = NULL;
		return;
	}

	else {
		if (head->val <=  pivot) {
			smaller = head;
			llpivot(head->next, smaller->next, larger, pivot);
		}
		else if (head->val > pivot) {
			larger = head;
			llpivot(head->next, smaller, larger->next, pivot);
		}
	}
}

bool Comp::operator()(int x) {
	if (x % 2 == 0) return false;
	else return true;
}


