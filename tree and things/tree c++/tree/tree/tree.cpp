#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// File Descriptors
ofstream outfile;
ifstream infile;

// Class Definition
class tNode
{
    // Typedefs
    typedef string tType;   // Declare typedef for all values in tree

    
        tNode* LChild;      // Points to the left branch of tree
        tType value;        // Value in node
        tNode* RChild;      // Points to the right branch of tree
    
        tNode()             // Default Constructor
        {
            LChild = NULL;
            RChild = NULL;
            value = "";
        }
        void PrintTree(tNode* treeRoot)
        // Prints out the contents of a tree, in order
        // from smallest to largest
        {
            if (treeRoot== NULL)
                return;
            PrintTree(treeRoot->LChild);
            cout << treeRoot->value;
            PrintTree(treeRoot->RChild);
        }
        tNode* myNewTNode()
        // Creates new tree node with a value,
        // a left child, and a right child (pointers)
        {
            tNode* temp;
            temp = new tNode;
            temp->value = "";
            temp->LChild = NULL;
            temp->RChild = NULL;
            return temp;
        }
        void insert(tNode* r, tType v)
        // Inserts values into tree
        {
            tNode* parent;
            tNode* temp;
            if (r == NULL)
            {
                r = myNewTNode();
                r->value = v;
                return;
            }
            while (r != NULL)
            {
                if (v < r->value)       // Smaller values will go on the left
                {
                    parent = r;         // Set parent to current root
                    r = r->LChild;      // Set root to point to the left side of tree
                }
                else if (v > r->value)  // Larger values go to the right
                {
                    parent = r;         // Set parent to current root
                    r = r->RChild;      // Set root to point to the right side of tree
                }
                temp = myNewTNode();    // Create a new node
                temp->value = v;        // Fill in the value
                if (v < parent->value)  // If passed in value is less than parent's value
                    parent->LChild = temp;// Place new node as parent's left child
                else if ( v> parent->value)// If passed in value is larger than parent's value
                    parent->RChild = temp; // Place new node as parent's right child
                return;
            }
		}};
		void main(){
			tNode* Salma= myNewTNode();

		
		}