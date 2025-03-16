#include <iostream>
#include "BST.h"	
using namespace std;




int main()
{
	BST<int> bst1;

	bst1.Add(45);
	bst1.Add(15);
	bst1.Add(79);
	bst1.Add(90);
	bst1.Add(10);
	bst1.Add(55);
	bst1.Add(12);
	bst1.Add(20);
	bst1.Add(50); 

	cout << "Display the tree contents\n";
	bst1.Preorder();
	cout << "\n\n\n";

	int value = 100;
	bool Result	 = bst1.Search(value);

	if (Result)
	{
		cout << value << " found in the tree\n";
	}
	else
		cout << value <<  " not found in the tree\n";

	cout << "\n\nPrint min value and max value in the Tree:\n";
	Node<int>* MinVal = bst1.FindMinimum(bst1.Root);
	Node<int>* MaxVal = bst1.FindMaximum(bst1.Root);

	cout << "\nMin Value is: " << MinVal->value << endl;
	cout << "Max Value is: " << MaxVal->value << endl;


	int ItemToDelete = 90;
	bst1.Delete(bst1.Root, ItemToDelete);
	cout << "\n\nDisplay the tree contents after deleting " << ItemToDelete << "\n";
	bst1.Preorder();


	cout << "\n\n\n";

	return 0;
}