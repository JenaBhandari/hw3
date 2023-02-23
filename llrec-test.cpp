#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
#include "stack.h"
#include "heap.h"
using namespace std;

#include <queue>
#include <algorithm>

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

void vprint(std::vector <int> const &a);

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


void vprint(std::vector <int> const &a) {
   std::cout << "Heap: ";

   for(int i=0; i < a.size(); i++)
   std::cout << a.at(i) << ' ';

    std::cout << endl;
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

struct Comp 
{ 
    //public: Comp(); 

    //void action(); 
    bool operator()(int &x) 
    { 
			/*
        if (x%2 == 0)
        {
            return (false); 
        }
        else
        {
            return (true);
        }
				*/

				if (x <= 5)
				{
					return true;
				}
				else
				{
					return false;
				}
    } 
};





int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    //Node* head = readList(argv[1]);
    //cout << "Original list: ";
    //print(head);

    // Test out your linked list code
/*
    Node *smaller = nullptr;
    Node *larger = nullptr;
    int pivot = 9;
    llpivot(head, smaller, larger, pivot);


    cout << "Original list: ";
    print(head);
    cout << "Smaller list: ";
    print(smaller);
    cout << "Larger list: ";
    print(larger);
*/


    //int x = 5;
    //int y = 6;
    //cout << pred(x) << " " << pred(y);
    
		//llfilter(head, pred);

    //cout << "After pivot: ";
    //print(head);

		//Node* list = makeList({2, 4, 8, 3});

        /*
		Node* list = readList(argv[1]);
		Node* small = (Node*) &list; // set to a non-null address
		Node* large = (Node*) &list; // set to a non-null address

		cout << "Original list: ";
		print(list);

		llpivot(list, small, large, 5);
    cout << "Original list: ";
    print(list);
    cout << "Smaller list: ";
    print(small);
    cout << "Larger list: ";
    print(large);

		list = readList(argv[1]);
		cout << "Round 2 original list: ";
		print(list);

		llfilter(list, pred);

		cout << "After filter: ";
		print(list);
		*/


}
