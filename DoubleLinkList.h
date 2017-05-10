#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H
#include<iostream>
#include<string>

using namespace std;


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
	DoubleLinkDataNode<T> *first;
	//DoubleLinkDataNode<int> headNode(0);  // "constant" compile error
	//DoubleLinkDataNode<int> *headPtr = new DoubleLinkDataNode<int>(0);  // but this works
	DoubleLinkDataNode<int> headNode;
	DoubleLinkDataNode<T> *last;

protected:
	// protected functions

public:
	// constructor
	DoubleLinkedList()
	{
		first = nullptr;
		last = nullptr;
		headNode.nextNode = reinterpret_cast<DoubleLinkDataNode<int>*>(first);
		//headNode(0);
	}
	
	void printLast()
	{
		cout << last->data;
	}

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
			DoubleLinkDataNode<T> *tempPtr = nullptr;
			tempPtr = first;
			tempPtr->previousNode = newNode;
			first = newNode;
			newNode->previousNode = nullptr;
			newNode->nextNode = tempPtr;
		}
		headNode.data++;
	}

	void push_last()
	{
		// push the new node as the last item in the list
	}

	void top(T &passedByReference)
	{
		// if the head is null, print the error message
		if (!first)
			cout << "error: no items in the list";

		// else, make the passed reference equal to the data stored in the first item
		else
		{
			passedByReference = first->data;
		}
	}

	void insert_node(T value)
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

		// else, attempt to insert the node based on its value.  
		else
		{
			DoubleLinkDataNode<T> *tempPtr = first;

			// if the first node is greater than Value, insert the new node as the first item in the list and update the link chain
			if (first->data > value)
			{
				first = newNode;
				newNode->nextNode = tempPtr;
			}
			// else, search the list for a node whoose data is less than the passed value
			else
			{
				while (tempPtr->data < value && tempPtr->nextNode != nullptr)
				{
					tempPtr = tempPtr->nextNode;
				}
				
				// if all the items in the list are lower than Value, insert the node at the end and update the link chain
				if (tempPtr->nextNode == nullptr)
				{
					tempPtr->nextNode = newNode;
					newNode->previousNode = tempPtr;
					last = newNode;
				}

				// insert the new node after tempPtr node and update the link chain
				else
				{
					newNode->nextNode = tempPtr->nextNode;
					newNode->previousNode = tempPtr;
					tempPtr->nextNode = newNode;
				}

			}
		}
		headNode.data++;
	}

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
				newNode->nextNode = currentNode;
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
	}

	void displayList()
	{
		// if there are no items in the list, display the message
		if (!first)
		{
			cout << "error: list is empty";
			cout << endl << "list count: " << headNode.data;
		}

		// else, display all the nodes
		else
		{
			DoubleLinkDataNode<T> *tempPtr;
			tempPtr = first;
			while (tempPtr->nextNode != nullptr)
			{
				cout << tempPtr->data << endl;
				tempPtr = tempPtr->nextNode;
			}
			cout << tempPtr->data << endl;
			cout << "list count: " << headNode.data;
		}
	}
};

#endif
