/*
 * bst.h
 *
 *  Created on: 14/10/2020
 *      Author: Luis Ramirez
 */

#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include "node.h"

using namespace std;
template <class T> class BST;


template<class T>
class BST{
	private:
	Node<T>* root=0;
	int max_depth;

	public:
	BST(){}
	BST(T val){
		Node<T>* node = new Node(val);
		root = node;
	}

	// Main functions
	void add(T val);

	// Other functions
	vector<T> level_traversal();
	string visit();
	int height();
	string ancestors(T val);
	int whatlevelamI(T val);
};



template<class T>
void BST<T>::add(T val){
	if (root == 0){
		Node<T>* new_node = new Node(val, 0);
		root = new_node;
		max_depth = 0;
	}else {
		root->add(val, 0, max_depth);
	}
}



template<class T>
int BST<T>::whatlevelamI(T val){
	if (root == 0) return -1;
	return root->level_at(val);
}



template<class T>
int BST<T>::height(){
	return max_depth+1;
}



template<class T>
Node<T>* pop(vector<Node<T>*>& arr){
	Node<T>* node;
	if (arr.size() == 0) return node;
	node = arr[arr.size()-1];
	arr.pop_back();
	return node;
}

template<class T>
vector<T> BST<T>::level_traversal(){
	vector<T> prints;
	vector<Node<T>*> queue;
	Node<T>* current = root;
	while (current != 0){
		prints.push_back(current->val);
		if (current->left != 0) queue.insert(queue.begin(), current->left);
		if (current->right != 0) queue.insert(queue.begin(), current->right);
		if (queue.size() > 0){
			current = pop(queue);
		} else {
			current = 0;
		}
	}

	return prints;
}



template<class T>
string BST<T>::visit(){
	if (root == 0) return "[]\n[]\n[]\n[]";

	stringstream answer;
	answer << "[";

	// Pre-order
	vector<int> preorder;
	vector<int> depth;
	root->visit(preorder, depth, 1);
	for (int i=0; i<preorder.size(); i++){
		answer << to_string(preorder[i]);
		if (i < preorder.size()-1) answer << " ";
	}
	answer << "]\n[";
	
	// In-order
	vector<int> inorder;
	root->visit(inorder, depth, 2);
	for (int i=0; i<inorder.size(); i++){
		answer << to_string(inorder[i]);
		if (i < inorder.size()-1) answer << " ";
	}
	answer << "]\n[";
	
	// Post-order
	vector<int> postorder;
	root->visit(postorder, depth, 3);
	for (int i=0; i<postorder.size(); i++){
		answer << to_string(postorder[i]);
		if (i < postorder.size()-1) answer << " ";
	}
	answer << "]\n[";

	// Level by level
	vector<T> level = level_traversal();
	for (int i=0; i<level.size(); i++){
		answer << to_string(level[i]);
		if (i < level.size()-1) answer << " ";
	}
	answer << "]";
	string answer2 = answer.str();
	return answer2;
}



template<class T>
string BST<T>::ancestors(T val){
	if (root == 0) return "[]";
	string answer = "[";
	vector<T> ancestors_vec;
	root->ancestors(val, ancestors_vec);
	for (int i=0; i<ancestors_vec.size(); i++){
		answer = answer + to_string(ancestors_vec[i]);
		if (i < ancestors_vec.size()-1) answer = answer + " ";
	}
	answer = answer + "]";
	return answer;
}