 #include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
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


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
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





int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* list1 = readList(argv[1]);
    Node* list2 = readList(argv[1]);
    cout << "------Testing llpivot()------" << endl;

    cout << "Original list: ";
    print(list1);
		Node* smaller = new Node(0, nullptr);
		Node* larger = new Node(0, nullptr);

		llpivot(list1, smaller, larger, 5);

        
		cout << "Smaller: ";
		print(smaller);
		cout << "Larger: ";
		print(larger);

		cout << "Testing if original list was preserved: " << endl;
		if (list1 == NULL) cout << "Success! List1 is NULL" << endl;
		else cout <<"Failed! List1 was preserved!" << endl;

		if (argc < 3) cout << "To test llpivot with garbage add another input file" << endl;
		else {
			Node* list3 = readList(argv[1]);
			cout << "------Testing llpivot() with garbage------" << endl;
			Node* smaller = readList(argv[2]);
			Node* larger = readList(argv[2]);
			cout << "Smaller before testing: ";
			print(smaller);
			cout << "Larger before testing: ";
			print(larger);

			cout << "List to Pivot: ";
			print(list3);
			llpivot(list3, smaller, larger, 10);
			cout << "Smaller after llpivot(): ";
			print(smaller);
			cout << "Larger after llpivot(): ";
			print(larger);
		}

    Comp pred;

    // Test out your linked list code

    cout << "------Testing llfilter()------" << endl;
    cout << "Original list: ";
    print(list2);
    cout << "Modified list: ";
    print(llfilter(list2, pred));

		


    
    return 0;

}
