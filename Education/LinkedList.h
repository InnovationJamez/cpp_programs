#include <iostream>

struct node{
	int data;
	node* next;
	node(int x);
}

class LinkedList{
private:
	node* head;
public:
	//function add node at front
	void addAtFront(node* n);

	//function to check whether the list is empty
	bool isEmpty();

	//function to add node at the end
	void addAtEnd(node* n);

	//function to search a value
	node* search(int k);

	//function to delete a note
	node* deleteNode(int x);

	//function to get a last note
	node* getLastNode();

	// function to print node list
	void printList();

	//constructor 
	LinkedList();

};


