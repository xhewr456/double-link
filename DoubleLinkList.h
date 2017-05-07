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
		data = 0;
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
	DoubleLinkDataNode<T> *head;
	DoubleLinkDataNode<int> headNode;
	DoubleLinkDataNode<T> *nodePTR;
	DoubleLinkDataNode<T> *last;

protected:
	// protected functions

public:
	// constructor
	DoubleLinkedList()
	{
		head = nullptr;
		nodePTR = nullptr;
		last = nullptr;
	}

	void push_front(T newData)
	{
		// dynamically create a new node and store value in it
		DoubleLinkDataNode<T> *newNode = new DoubleLinkDataNode<T>(newData);

		// if there are no items in the list, make newNode the first item and make last point to the new node
		if (!head)
		{
			head = newNode;
			last = newNode;
			newNode->previousNode = nullptr;
			newNode->nextNode = nullptr;
		}

		// else, add the new node to the front of the list and update the link chain
		else
		{
			DoubleLinkDataNode<T> *tempPtr = nullptr;
			tempPtr = head;
			tempPtr->previousNode = newNode;
			head = newNode;
			newNode->previousNode = nullptr;
			newNode->nextNode = tempPtr;
			//headNode->data++;
		}

	}
	void top(T &passedByReference)
	{
		// if the head is null, print the error message
		if (!head)
			cout << "error: no items in the list";

		// else, make the passed reference equal to the data stored in the first item
		else
		{
			passedByReference = head->data;
		}
	}

	void insert_node(T value)
	{
		// dynamically create a new node and store value in it
		DoubleLinkDataNode<T> *newNode = new DoubleLinkDataNode<T>(value);

		// if there are no items in the list, make newNode the first item and make last point to the new node
		if (!head)
		{
			head = newNode;
			last = newNode;
			newNode->previousNode = nullptr;
			newNode->nextNode = nullptr;
		}

		// else, attempt to insert the node based on its value.  
		else
		{
			DoubleLinkDataNode<T> *tempPtr = head;

			// if the first node is greater than Value, insert the new node as the first item in the list and update the link chain
			if (head->data > value)
			{
				head = newNode;
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
	}

	void insert_node(T value, int index)
	{
		// dynamically create a new node and store value in it
		DoubleLinkDataNode<T> *newNode = new DoubleLinkDataNode<T>(newData);

		// if there are no items in the list, make newNode the first item and make last point to the new node
		if (!head)
		{
			head = newNode;
			last = newNode;
			newNode->previousNode = nullptr;
			newNode->nextNode = nullptr;
		}

		else
		{

		}

	}

	void displayList()
	{
		// if there are no items in the list, display the message
		if (!head)
			cout << "error: list is empty";

		// else, display all the nodes
		else
		{
			DoubleLinkDataNode<T> *tempPtr;
			tempPtr = head;
			while (tempPtr->nextNode != nullptr)
			{
				cout << tempPtr->data << endl;
				tempPtr = tempPtr->nextNode;
			}
			cout << tempPtr->data << endl;
		}
	}
};

#endif