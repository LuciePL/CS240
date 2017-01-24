#include "BSTree.h"
#include <iostream>

bool BSTree::insert(int val){
	if(root == NULL){
		root = new Node(val);
		return true;
	}
	return insert(val,root);

}

bool BSTree::insert(int val, Node* node){
	if(val > node->data){
		if(node->right == NULL){
			node->right = new Node(val);
			node->right->parent = node;
			return true;
		}
		else{
			return insert(val,node->right);
		}
	}
	else if(val < node->data){
		if(node->left == NULL){
			node->left = new Node(val);
			node->left->parent = node;
			return true;
		}
		else{
			return insert(val,node->left);
		}
	}
		
	else{
		return false;
	}
}

bool BSTree::find(int val){
	if(root == NULL){
		return false;
	}
	else{
		return find(val,root);
	}
}
bool BSTree::find(int val, Node* node){
	if(val > node->data){
		if(node->right == NULL){
			return false;
		}
		else{
			return find(val,node->right);
		}
	}
	else if(val < node->data){
		if(node->left == NULL){
			return false;
		}
		else{
			return find(val,node->left);
		}
	}
		
	else{
		return true;
	}
}

bool BSTree::empty(){
	if(root == NULL){
		return true;
	}
	else{
		return false;
	}
}
