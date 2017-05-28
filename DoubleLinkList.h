#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H
#include<iostream>
//#include<string>

//using namespace std;


template <class T>
class DoubleLinkDataNode
{
private:
	T data;
	DoubleLinkDataNode <T>*nextNode;
	DoubleLinkDataNode <T>*previousNode;
public:
	DoubleLinkDataNode()
	{
		//data = 0;
		nextNode = nullptr;
		previousNode = nullptr;
	}
	DoubleLinkDataNode(T newValue)
	{
		data = newValue;
		nextNode = nullptr;
		previousNode = nullptr;
	}
	template <class T>
	friend class DoubleLinkedList;
};


template <class T>
class DoubleLinkedList
{
private:
	//DoubleLinkDataNode<int> headNodeTest(0);  // "constant" compile error
	//DoubleLinkDataNode<int> *headPtr;// = new DoubleLinkDataNode<int>(0);  // but this works
	DoubleLinkDataNode<int> headNode;  // create an instance of the node object and not merely a pointer
	DoubleLinkDataNode<T> *first;
	DoubleLinkDataNode<T> *last;
	int listCount;
protected:
	// protected functions

public:
	// constructor
	DoubleLinkedList()
	{
		//headPtr = new DoubleLinkDataNode<int>(0);  // but this works
		listCount = 0;  // number of items in the list
		first = nullptr;
		last = nullptr;
		//headNode.nextNode = reinterpret_cast<DoubleLinkDataNode<int>*>(first);
	}

	// destructor
	~DoubleLinkedList()
	{
		DoubleLinkDataNode<T> *currentNode = nullptr; // To traverse the list
		DoubleLinkDataNode<T> *nextNode = nullptr; // To point to the next node

		// Position currentNode at the beginning of the list.
		currentNode = first;

		// While currentNode is not at the end of the list...
		while (currentNode != nullptr)
		{
			nextNode = currentNode->nextNode;
			delete currentNode;
			currentNode = nextNode;
		}
	}

	// debug function
	void printFirst()
	{
		std::cout << "print First: " << first->data;
	}

	// debug function
	void printLast()
	{
		std::cout << "print Last: " << last->data;
	}

	// add new item as the first item of the list
	void push_first(T newData)
	{
		// dynamically create a new node and store value in it
		DoubleLinkDataNode<T> *newNode = new DoubleLinkDataNode<T>(newData);

		// if there are no items in the list, make newNode the first item and make last point to the new node
		if (!first)
		{
			first = newNode;
			last = newNode;
			newNode->previousNode = nullptr;
			newNode->nextNode = nullptr;
		}

		// else, add the new node to the front of the list and update the link chain
		else
		{
			newNode->previousNode = nullptr;
			newNode->nextNode = first;
			first->previousNode = newNode;
			first = newNode;
		}
		// increment the item counter
		headNode.data++;
		listCount++;
	}

	void push_last(T newData)
	{
		// push the new node as the last item in the list
		DoubleLinkDataNode<T> *newNode = new DoubleLinkDataNode<T>(newData);

		// if there are no items in the list, make newNode the first item and make last point to newNode
		if (!first && !last)
		{
			first = newNode;
			last = newNode;
			newNode->previousNode = nullptr;
			newNode->nextNode = nullptr;
		}

		// else, 
		else
		{
			newNode->previousNode = last;
			newNode->nextNode = nullptr;
			last->nextNode = newNode;
			last = newNode;
		}
		// increment the item counter
		headNode.data++;
		listCount++;
	}

	void pop_front()
	{
		// remove the first item in the list

		if (!first)
		{
			std::cout << "error: list is empty";
		}

		else
		{
			DoubleLinkDataNode<T> *currentPtr = nullptr;
			currentPtr = first;

			if (listCount == 1)
			{
				delete currentPtr;
				first = nullptr;
				last = nullptr;
			}

			else
			{
				first = currentPtr->nextNode;
				first->previousNode = nullptr;
				delete currentPtr;
			}
			// decrement the item counter
			headNode.data--;
			listCount--;
		}
	}

	void pop_last()
	{
		// remove the last item in the list

		if (!first && !last)
		{
			std::cout << "error: list is empty";
		}

		else
		{
			DoubleLinkDataNode<T> *currentPtr = nullptr;
			currentPtr = last;

			if (listCount == 1)
			{
				delete currentPtr;
				first = nullptr;
				last = nullptr;
			}

			else
			{
				last = currentPtr->previousNode;
				last->nextNode = nullptr;
				delete currentPtr;
			}
			// decrement the item counter
			headNode.data--;
			listCount--;
		}
	}

	T getFirst()
	{
		return first->data;
	}

	T getLast()
	{
		return last->data;
	}

	T getIndex(int index)
	{
		DoubleLinkDataNode<T> *currentNode = nullptr;
		currentNode = first;
		for (int count = 0; count < index; count++)
		{
			currentNode = currentNode->nextNode;
		}
		return currentNode->data;
	}

	//void top(T &passedByReference)
	//{
	//	// if the head is null, print the error message
	//	if (!first)
	//		std::cout << "error: no items in the list";

	//	// else, make the passed reference equal to the data stored in the first item
	//	else
	//	{
	//		passedByReference = first->data;
	//	}
	//}

	//void insert_node(T value)
	//{
	//	// dynamically create a new node and store value in it
	//	DoubleLinkDataNode<T> *newNode = new DoubleLinkDataNode<T>(value); 
	//	// if there are no items in the list, make newNode the first item and make last point to the new node
	//	if (!first)
	//	{
	//		first = newNode;
	//		last = newNode;
	//		newNode->previousNode = nullptr;
	//		newNode->nextNode = nullptr;
	//	}
	//	// else, attempt to insert the node based on its value.  
	//	else
	//	{
	//		DoubleLinkDataNode<T> *tempPtr = first;
	//		// if the first node is greater than Value, insert the new node as the first item in the list and update the link chain
	//		if (first->data > value)
	//		{
	//			first = newNode;
	//			newNode->nextNode = tempPtr;
	//		}
	//		// else, search the list for a node whoose data is less than the passed value
	//		else
	//		{
	//			while (tempPtr->data < value && tempPtr->nextNode != nullptr)
	//			{
	//				tempPtr = tempPtr->nextNode;
	//			}
	//			// if all the items in the list are lower than Value, insert the node at the end and update the link chain
	//			if (tempPtr->nextNode == nullptr)
	//			{
	//				tempPtr->nextNode = newNode;
	//				newNode->previousNode = tempPtr;
	//				last = newNode;
	//			}
	//			// insert the new node after tempPtr node and update the link chain
	//			else
	//			{
	//				newNode->nextNode = tempPtr->nextNode;
	//				newNode->previousNode = tempPtr;
	//				tempPtr->nextNode = newNode;
	//			}
	//		}
	//	}
	//	headNode.data++;
	//}

	void insert_node(T value, int index)
	{
		// dynamically create a new node and store value in it
		DoubleLinkDataNode<T> *newNode = new DoubleLinkDataNode<T>(value);

		// if there are no items in the list, make newNode the first item and make last point to the new node
		if (!first)
		{
			first = newNode;
			last = newNode;
			newNode->previousNode = nullptr;
			newNode->nextNode = nullptr;
		}

		else
		{
			DoubleLinkDataNode<T> *currentNode = first;

			// if location is 1
			if (index == 1)
			{
				newNode->nextNode = first;
				newNode->previousNode = nullptr;
				first = newNode;
			}

			else
			{
				DoubleLinkDataNode<T> *previous = nullptr;

				// list does not start at zero, the first element is item one
				for (int count = 1; (count < index && currentNode->nextNode != nullptr); count++)
				{
					previous = currentNode;
					currentNode = currentNode->nextNode;
				}

				// if the current node points to null, set the new node as the last item in the list and update last to point to new node
				if (currentNode->nextNode == nullptr)
				{

					currentNode->nextNode = newNode;
					newNode->nextNode = nullptr;
					newNode->previousNode = currentNode;
					last = newNode;
				}

				// else, the node is inserted somewhere in the list that is not first or last
				else
				{
					previous->nextNode = newNode;
					newNode->nextNode = currentNode;
					newNode->previousNode = previous;
					currentNode->previousNode = newNode;
				}
			}
		}
		headNode.data++;
		listCount++;
	}

	void displayList()
	{
		// if there are no items in the list, display the message
		if (!first)
		{
			std::cout << "error: list is empty";
		}

		// else, display all the nodes
		else
		{
			DoubleLinkDataNode<T> *currentPtr = nullptr;
			currentPtr = first;
			while (currentPtr != nullptr)
			{
				std::cout << currentPtr->data << endl;
				currentPtr = currentPtr->nextNode;
			}
			//std::cout << "list count: " << headNode.data;
		}
	}

	// return the number of items in the list
	int listSize()
	{
		return headNode.data;
	}

	void emptyList()
	{
		DoubleLinkDataNode<T> *currentNode = nullptr; // To traverse the list
		DoubleLinkDataNode<T> *nextNode = nullptr; // To point to the next node

		// Position currentNode at the beginning of the list.
		currentNode = first;

		// While currentNode is not at the end of the list...
		while (currentNode != nullptr)
		{
			nextNode = currentNode->nextNode;
			delete currentNode;
			currentNode = nextNode;
		}

		// now the list can be used again
		first = nullptr;
		last = nullptr;
	}

};

#endif
