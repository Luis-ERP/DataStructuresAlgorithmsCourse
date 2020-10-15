#include<iostream>
#include<string>
using namespace std;

 

// ------------------ CLASS NODE ----------------------
template<class T>
class Node{
	private:
	T val;
	Node<T>* next=0;
	Node<T>* previous=0;

	Node(T val_){
		val = val_;
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
			temp->previous = this;
			next = temp;
		} else {
			val = next->remove(index-1);
		}
		return val;
	}

	template <class> friend class DList;
};






// ----------------- CLASS DList ----------------------------
template<class T>
class DList{
private:
	Node<T>* root=0;
	Node<T>* tail=0;
	int length=0;

public:
	DList(){}
	DList(T value){
		root->val = value;
		length++;
	}
	
	string toStringForward() const;
	string toStringBackward() const;

	void add(T val);
	int find(T val);
	void update(int index, T val);
	T remove(int index);
	
};


template<class T>
// ADD NEW NODE TO DList
void DList<T>::add(T val){
	Node<T>* new_node = new Node<T>(val);
	if (tail == 0){
		tail = new_node;
		root = new_node;
	} else{
		tail->next = new_node;
		new_node->previous = tail;
		tail = new_node;
	}
	length++;
}


template<class T>
// FIND VALUE
int DList<T>::find(T val){
	int answer;
	if (root != 0){
		answer = root->find(val, 0);
	}
	return answer;
}


template<class T>
// UPDATE ELEMENT OF DList
void DList<T>::update(int index, T val){
	if (root != 0){
		root->update(index, val);
	}
}


template<class T>
// REMOVE ELEMENT FROM STRING
T DList<T>::remove(int index){
	T val;
	bool ans = index == length-1;
	if (index == 0){
		if (length == 1){
			delete(root);
			tail = 0;
			root = 0;
		} else {
			val = root->val;
			Node<T>* temp = root->next;
			delete(root);
			temp->previous = 0;
			root = temp;
		}		
	} 
	else if (index == length-1){
		Node<T>* temp_tail = tail->previous;
		val = tail->val;
		temp_tail->next = 0;
		delete(tail);
		tail = temp_tail;
	} else {
		val = root->remove(index-1);
	}
	length--;
	return val;
}






template <class T>
string DList<T>::toStringForward() const {
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

template <class T>
string DList<T>::toStringBackward() const {
	stringstream aux;
	Node<T> *p;

	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->val;
		if (p->previous != 0) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}
