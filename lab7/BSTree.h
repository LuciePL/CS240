#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <vector>


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
		Node* findNode(int val);
		Node* findNode(int val, Node* node);
		Node* findMin(Node* n);
		std::vector<int>& preOrder(std::vector<int> &data, Node* toOrder);
		void inOrder(std::vector<int> &list, Node* toOrder);
		bool shortCircuit(Node* n);
		bool promotion(Node* n);
		std::vector<int>& postOrder(std::vector<int> &list, Node* toOrder);

	public:
	BSTree(){
		root = NULL;
	}
	BSTree(const BSTree &old_tree);
	~BSTree();
	bool empty();
	bool insert(int val);
	bool insert(int val, Node* node);
	bool find(int val);
	bool find(int val, Node* node);
	//std::vector<int>& preOrder(std::vector<int> &data, Node* toOrder);
	bool remove(int num);
	void sortedArray(std::vector<int> &list);
	bool removeLeaf(Node* leaf);
	//void inOrder(std::vector<int> &list, Node* toOrder);
	//bool shortCircuit(Node* n);
	//bool promotion(Node* n);
	//std::vector<int>& postOrder(std::vector<int> &list, Node* toOrder);
	
};

#endif
