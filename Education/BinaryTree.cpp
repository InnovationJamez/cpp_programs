#include <iostream>

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int data);
};

Node::Node(int data){
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

void print(Node *root, int space=0, int t=0){
	int COUNT = 3;

	if(root == NULL){
		return;
	}

	space += COUNT;

	print(root->right, space, 1);

	for(int i = COUNT; i < space; i++){
		std::cout << " ";
	}
	if(t == 1){
		std::cout << "/ " << root->data << std::endl;
	}
	else if (t == 2){
		std::cout << "\\ " << root->data << std::endl;
	}
	else{
		std::cout << root->data << std::endl;
	}

	print(root->left, space, 2);
}


int main(){
	Node *root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(11);
	root->right->left->left = new Node(12);
	root->right->left->right = new Node(13);
	root->right->right->left = new Node(14);
	root->right->right->right = new Node(15);

	print(root);
}