/*
 * splay.h
 *
 *  Created on: 19/10/2020
 *      Author: Luis Edgar Ramirez.
 */	


#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "node.h"

using namespace std;

template <class T> class SplayTree;


template<class T>
class SplayTree{
private:
	Node<T> *root;
	int size=0;
	
public:
	SplayTree();
	~SplayTree();
	bool empty() const;
	void add(T);
	bool find(T);
	void remove(T);
	void removeAll();
	string inorder() const;
	string print_tree() const;
	string preorder() const;
	int size();
};


template <class T>	
SplayTree<T>::SplayTree():root(0) {}


template<class T>
SplayTree<T>::~SplayTree() {
	removeAll();
}
	

template<class T>
bool SplayTree<T>::empty() const{
	return (root==0);
}


template<class T>
void SplayTree<T>::add(T val){
	
	if(root !=0){
		Node<T>* added= root->add(val);
		root=root->splay(root,added);
	}else{
		root=new Node<T>(val);
	}
	size+=1;
}
	

template<class T>
void SplayTree<T>::remove(T val){
	if(root!=0){
		if(val==root->value){
			Node<T> *succ=root->succesor();
			if(succ !=0){
				succ->left = root->left;
				succ->right=root->right;
				succ->parent=0;
				if(succ->left)
					succ->left->parent=succ;
				if(succ->right)
					succ->right->parent=succ;
			}
			delete root;
			root=succ;
		}else {
			Node<T>*p = root->remove(val);
			if (p != 0)
				root=root->splay(root,p);
		}
	}
	size-=1;
}


template<class T>
void SplayTree<T>::removeAll(){
	if(root !=0){
		root->removeChilds();
	}
	delete root;
	root=0;
	size=0;
}
	

template<class T>
bool SplayTree<T>::find(T val){
	if(root!=0){
		Node<T>* found=root->find(val);
		if (found == 0) return false;
		root=root->splay(root,found);
		return(root->value==val);
	}else{
		return false;
	}
}


template<class T>
string SplayTree<T>::inorder() const{
	stringstream aux;
	
	aux<<"[";
	if(!empty()){
		root->inorder(aux);
	}
	aux<<"]";
	return aux.str();
}
	

template<class T>
string SplayTree<T>::print_tree() const{
	stringstream aux;
	
	aux<<"\n ====================== ";
	if(!empty()){
		root->print_tree(aux);
	}
	aux<<" ==================== \n";
	return aux.str();
}
	
	
template<class T>
string SplayTree<T>::preorder() const{
	stringstream aux;
	
	aux<<"[";
	if(!empty()){
		root->preorder(aux);
	}
	aux<<"]";
	return aux.str();
}	


template<class T>
int SplayTree<T>::size(){
	return size;
}
