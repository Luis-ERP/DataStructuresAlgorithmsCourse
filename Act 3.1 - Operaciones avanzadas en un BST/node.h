/*
 * node.h
 *
 *  Created on: 14/10/2020
 *      Author: Luis Ramirez
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "bst.h"

using namespace std;
template <class T> class BST;



template<class T>
class Node{
	private:
	T val;
	int level;
	Node* left;
	Node* right;

	public:
	Node(){}
	Node(T _val, int _level){val = _val; level = _level;}

	int level_at(T _val);
	void add(T _val, int current_depth, int& max_depth);
	void visit(vector<int>& prints, vector<int>& depths, int check);
	void ancestors(T _val, vector<T>& ancestors_vec);

	friend class BST<T>;
};


// --------------------------------------------------------------------


template<class T>
void Node<T>::add(T _val, int current_depth, int& max_depth){
	current_depth++;
	if (_val == val){
		return;
	}
	else if (_val < val){
		if (left != 0)
			left->add(_val, current_depth, max_depth);
		else{
			Node* new_node = new Node(_val, current_depth+1);
			left = new_node;
			if (current_depth > max_depth){
				max_depth = current_depth;
			}
		}
	}
	
	else {
		if (right != 0)
			right->add(_val, current_depth, max_depth);
		else{
			Node* new_node = new Node(_val, current_depth+1);
			right = new_node;
			if (current_depth > max_depth){
				max_depth = current_depth;
			}
		}
	}
	
}


template<class T>
void Node<T>::visit(vector<int>& prints, vector<int>& depths, int check){
	// Add +1
	int counter = 1;
	if (counter == check)
		prints.push_back(val);
	// Visit left node
	if (left != 0){
		left->visit(prints, depths, check);
	}
	// Add +1
	counter++;
	if (counter == check)
		prints.push_back(val);
	// Visit right node
	if (right != 0){
		right->visit(prints, depths, check);
	}
	// Add +1
	counter++;
	if (counter == check)
		prints.push_back(val);
}


template<class T>
int Node<T>::level_at(T _val){
	if (_val == val){
		return level;
	}
	if (left != 0){
		if (_val < val) return left->level_at(_val);
	}
	if (right != 0){
		if (_val > val) return right->level_at(_val);
	}
	return -1;
}



template<class T>
void Node<T>::ancestors(T _val, vector<T>& ancestors_vec){
	if (_val == val) return;
	
	if ((_val > val) && (right != 0)){
		ancestors_vec.push_back(val);
		right->ancestors(_val, ancestors_vec);
	} else {
		ancestors_vec = {};
	}	
}