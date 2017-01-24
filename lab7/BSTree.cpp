#include "BSTree.h"
#include <iostream>
#include <vector>

	BSTree::BSTree(const BSTree &old_tree){
		std::vector<int> anything;
		anything = preOrder(anything,old_tree.root);
		for(int i =0; i < anything.size(); i++){
			insert(anything[i]);
		}
		while(!anything.empty()){
			anything.erase(anything.begin());
		}
	}

	BSTree::~BSTree(){
	std::vector<int> anything;
	anything = postOrder(anything, root);
	for(int i = 0; i< anything.size(); i++){
		remove(anything[i]);
	}
	while(!anything.empty()){
		anything.erase(anything.begin());
	}
}

	BSTree::Node* BSTree::findNode(int val){
	if(root == NULL){
		return NULL;
	}
	else{
		return findNode(val,root);
	}
}
BSTree::Node* BSTree::findNode(int val, Node* node){
	if(val > node->data){
		if(node->right == NULL){
			return NULL;
		}
		else{
			return findNode(val,node->right);
		}
	}
	else if(val < node->data){
		if(node->left == NULL){
			return NULL;
		}
		else{
			return findNode(val,node->left);
		}
	}
		
	else{
		return node;
	}
}

BSTree::Node* BSTree::findMin(Node* n){
	if(n->right == NULL){
		return n;
	}
	else{
		findMin(n->right);
	}
}

std::vector<int>& BSTree::preOrder(std::vector<int> &data, Node* toOrder){
	if(toOrder == NULL){
		return data;
	}
	data.push_back(toOrder->data);
	preOrder(data,toOrder->left);
	preOrder(data,toOrder->right);
	return data;
}

void BSTree::inOrder(std::vector<int> &list, Node* toOrder){
	if(toOrder == NULL){
		return;
	}
	inOrder(list,toOrder->left);
	list.push_back(toOrder->data);
	inOrder(list,toOrder->right);
}

bool BSTree::shortCircuit(Node* n){
	if(n == root){
		if(n->left != NULL){
			root = n->left;
		}
		else{
			root = n->right;
		}
	}
	else{
		if(n->parent->right == n){
			if(n->right == NULL){
				n->left->parent = n->parent;
				n->parent->right = n->left;
			}
			else{
				n->right->parent = n->parent;
				n->parent->right = n->right;
			}
		}
		else if(n->parent->left == n){
			if(n->right == NULL){
				n->left->parent = n->parent;
				n->parent->left = n->left;
			}
			else{
				n->right->parent = n->parent;
				n->parent->left = n->right;
			}
		}
	}
	delete n;
	return true;
}

bool BSTree::promotion(Node* n){
	Node* temp = findMin(n->left);
	n->data = temp->data;
	if(temp->left == NULL && temp->right == NULL){
		removeLeaf(temp);
	}
	else{
		shortCircuit(temp);
	}
}

std::vector<int>& BSTree::postOrder(std::vector<int> &list, Node* toOrder){
	if(toOrder == NULL){
		return list;
	}
	postOrder(list,toOrder->left);
	postOrder(list, toOrder->right);
	list.push_back(toOrder->data);
	return list;
}

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



bool BSTree::remove(int num){
	if(findNode(num)!= NULL){
		Node* nodeL = findNode(num);
		if(nodeL->left == NULL && nodeL->right == NULL){
			return removeLeaf(nodeL);
		}
		else if(nodeL->left == NULL || nodeL->right == NULL){
			return shortCircuit(nodeL);
		}
		else{
			return promotion(nodeL);
		}
	}
	else{
		return false;
	}
	//return true;
}

void BSTree::sortedArray(std::vector<int> &list){
	inOrder(list,root);
}

bool BSTree::removeLeaf(Node* leaf){
	if(leaf == root){
		root = NULL;
	}
	else{
		if(leaf->parent->right == leaf){
			leaf->parent->right = NULL;
		}
		else{
			leaf->parent->left = NULL;
		}
	}
	delete leaf;
	return true;
}


