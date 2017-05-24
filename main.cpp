#include<iostream>
#include<string>
#include"DoubleLinkList.h"

using namespace std;


int main()
{
	DoubleLinkDataNode<int> testnodeint(0);
	DoubleLinkedList<int> testList;
	//testList.push_first(1);
	//testList.push_first(3);
	//testList.push_first(5);
	//testList.push_first(7);
	//testList.push_first(9);
	testList.insert_node(11, 1);
	testList.insert_node(7, 2);
	testList.insert_node(5, 3);
	testList.insert_node(3, 4);
	//testList.insert_node(2.2,3);
	testList.insert_node(0, 1);
	testList.displayList();
	testList.insert_node(2, 5);
	cout << endl;
	testList.displayList();
	//string x;
	//double x;
	//testList.top(x);
	cout << "\n\n";
	testList.printLast();
	cout << "\n\n";
	testList.printFirst();
	DoubleLinkedList<string> strList;
	strList.push_first("one");
	strList.push_first("three");
	strList.push_first("five");
	strList.push_first("seven");
	strList.push_first("eleven");
	cout << endl << endl;
	strList.displayList();
	cout << endl;
	string y;
	y = strList.getFirst();
	//strList.top(y);
	cout << y << endl;
	y = strList.getLast();
	cout << y << endl;
	DoubleLinkedList<string> str2List;
	cout << endl;
	str2List.displayList();
	//int xyz;
	//cout << endl << xyz;


	cout << "\n\npress <Enter> to exit the program...";
	cin.get();
	return 0;
}