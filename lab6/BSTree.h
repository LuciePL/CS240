#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>


class BSTree{
	private:
		class Node{
			public:
				int data;
				Node* left;
				Node* right;
				Node* parent;
				Node(int data){
					this->data = data;
					this->left = NULL;
					this->right = NULL;
					this->parent = NULL;
				}
		};
		Node* root;
	public:
	BSTree(){
		root = NULL;
	}
	bool empty();
	bool insert(int val);
	bool insert(int val, Node* node);
	bool find(int val);
	bool find(int val, Node* node);
};

#endif
