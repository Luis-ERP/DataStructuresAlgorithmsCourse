#include<iostream>
#include<string>
using namespace std;

 

// ------------------ CLASS NODE ----------------------
template<class T>
class Node{
private:
	T val;
	Node<T>* next=0;

	Node(T val_){
		val = val_;
	}

	void add(Node<T>* node){
		if (next == 0){
			next = node;
		}
		else{
			next->add(node);
		}
	}

	int find(T _val, int counter){
		if (val == _val){
			return counter;
		} else {
			if (next == 0){
				return -1;
			}
			return next->find(_val, counter+1);
		}
	}

	void update(int index, T _val){
		if (index == 0){
			val = _val;
		} else {
			next->update(index-1, _val);
		}
	}

	T remove(int index){
		T val;
		if (index == 0){
			val = next->val;
			Node<T>* temp = next->next;
			delete(next);
			next = temp;
		} else {
			val = next->remove(index-1);
		}
		return val;
	}

	template <class> friend class List;
};






// ----------------- CLASS LIST ----------------------------
template<class T>
class List{
private:
	Node<T>* root=0;
	int length=0;

public:
	List(){}
	List(T value){
		root->val = value;
		length++;
	}
	
	string toString() const;

	void add(T val);
	int find(T val);
	void update(int index, T val);
	T remove(int index);
	
};


template<class T>
// ADD NEW NODE TO LIST
void List<T>::add(T val){
	if (root == 0){
		Node<T>* new_node = new Node<T>(val);
		root = new_node;
		length++;
	}
	else {
		Node<T>* new_node = new Node<T>(val);
		root->add(new_node);
		length++;
	}
}

template<class T>
// FIND VALUE
int List<T>::find(T val){
	int answer;
	if (root != 0){
		answer = root->find(val, 0);
	}
	return answer;
}

template<class T>
// UPDATE ELEMENT OF LIST
void List<T>::update(int index, T val){
	if (root != 0){
		root->update(index, val);
	}
}

template<class T>
// REMOVE ELEMENT FROM STRING
T List<T>::remove(int index){
	T val;
	if (index == 0){
		val = root->val;
		Node<T>* temp = root->next;
		delete(root);
		root = temp;
	} else {
		val = root->remove(index-1);
	}
	length--;
	return val;
}

template<class T>
string List<T>::toString() const {
	stringstream aux;
	Node<T> *p;

	p = root;
	aux << "[";
	while (p != 0) {
		aux << p->val;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}
