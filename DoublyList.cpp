#include "DoublyList.h"

//constructor
DoublyList::DoublyList()
{
	count = 0;
	first = NULL;
	last = NULL;
}

//destructor
DoublyList::~DoublyList()
{
	//destroyList();
}

//printForward
void DoublyList::printForward() const
{
	if (first == NULL)
		cerr << "Cannot print from an empty list." << endl;
	else
	{
		Node *current = first;

		while (current != NULL)
		{
			cout << current->getData() << " ";
			current = current->getNextLink();
		}
	}
}

//insertFront
void DoublyList::insertFront(int newData)
{
	Node *newNode = new Node(newData, NULL, first); // points to first, prev link to null

	if (first == NULL)
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		first->setPreviousLink(newNode);
		first = newNode;
	}
	++count;
}

//search
bool DoublyList::search(int key) const
{
	if (first == NULL)
		cerr << "Cannot search from an empty list." << endl;
	else
	{
		Node *current = first;
		bool found = false;
		while (current != NULL && !(found))
		{
			if (current->getData() == key)
			{
				found = true;
				return true;
			}
			else
				current = current->getNextLink();
		}
	}
	return false;
}

//deleteNode
void DoublyList::deleteNode(int deleteData)
{
	// Case 1: The list is empty.
	if (first == NULL)
		cerr << "Cannot delete from an empty list." << endl;
	else
	{
		Node *current = first;

		// Case 2: The node to be deleted is the first node
		if (first->getData() == deleteData)
		{
			first = first->getNextLink();

			// Case 2a: The list has only one node.
			if (first == NULL)
				last = NULL;
			else
				first->setPreviousLink(NULL);

			--count;
			delete current;
			current = NULL;
		}
		else // start searching the list abcdefghijklmnopqrstuvwxyz
		{
			bool found = false;
			
			while (current != NULL && !found)
			{
				if (current->getData() == deleteData)
					found = true;
				else
					current = current->getNextLink();
			}

			if (current == NULL) // if (!found)
				cerr << "The item to be deleted is not in the list." << endl;
			else
			{
				// Case 3: The item to be deleted is in the middle of the list.
				if (current != last)
				{
					current->getPreviousLink()->setNextLink(current->getNextLink());
					current->getNextLink()->setPreviousLink(current->getPreviousLink());
				}
				// Case 4: The item to be deleted is the last node.
				else
				{
					last = current->getPreviousLink();
					last->setNextLink(NULL);
				}
				--count;
				delete current;
				current = NULL;
			}
		}
	}
}

//destroyList - When would we use this function?
void DoublyList::destroyList()
{
	Node *temp;

	while (first != NULL)
	{
		temp = first;
		first = first->getNextLink();
		delete temp;
		temp = NULL; // not necessary
	}
	last = NULL;
	count = 0; // efficient compared 
			   // to decrementing it in the while loop
}