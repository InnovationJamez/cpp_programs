#include "LinkedList.h"

node::node(int x){
	data = x;
	next = nullptr;
} 

//function add node at front
void LinkedList::addAtFront(node* n){
	n->next = head;
	head = n;
}

//function to check whether the list is empty
bool LinkedList::isEmpty(){
	if(head == nullptr){
		return 0;
	}
	else{
		return 1;
	}
}

//function to add node at the end
void LinkedList::addAtEnd(node* n){
	if(head == nullptr){
		head = n;
		n->next = nullptr;
	}
	else{
		node* n2 = getLastNode();
		n2->next = n;
	}
}

//function to search a value
node* LinkedList::search(int k){
	node* ptr = head;
	while(ptr != nullptr &&ptr->data != k){
		ptr = ptr->next;
	}
	return ptr;
}

//function to delete a note
LinkedList::deleteNode(int x){
	node* n = search(x);
	node* ptr = head;
	if(ptr == n){
		head = n->next;
		return n;
	}
}

//function to get a last note
LinkedList::getLastNode(){
	node *n = search(x);
	node *ptr = head;

	if(ptr == n){
		head = n->next;
		return n;
	}
	else{
		while(ptr->next != n){
			ptr = ptr->next;
		}
		ptr->next = ptr->next;
	}
}

// function to print node list
LinkedList::printList(){
	node* ptr = head;
	while(ptr != nullptr){
		std::cout << ptr->data << " -> ";
		ptr = ptr->next;
	}
}

//constructor 
LinkedList::LinkedList(){
	head = nullptr;
}

int main(){

}