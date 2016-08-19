#ifndef DOUBLE_LIKEDLIST_H_
#define DOUBLE_LIKEDLIST_H_
#include <bits/stdc++.h>
using namespace std;
template <class T>
class Linkedlist {
	class Node {
		friend class Linkedlist;
		Node *next, *prev;
		T value;
	public:
		Node() {
			next = prev = NULL;
		}
		Node(T val) {
			value = val;
			next = prev = NULL;
		}
	};
	Node *head, *tail;
	int size;
public:
	Linkedlist() {
		head = tail = NULL;
		size = 0;
	}
	~Linkedlist() {
		Node *cur = head;
		while(cur) {
			Node *temp = cur;
			cur = cur->next;
			delete temp;
		}
		size = 0;
	}
	Linkedlist(const Linkedlist& otherlist) {
		size = otherlist.size;
		head = tail = NULL;
		if(size == 0)
			return ;
		Node *other_cur = otherlist.head->next;
		head = new Node(otherlist.head->value);
		Node *cur = head;
		while(other_cur) {
			cur->next = new Node(other_cur->value);
			cur->next->prev = cur;
			cur = cur->next;
			other_cur = other_cur->next;
		}
		tail = cur;
	}
	void push_front(T val) {
		Node *temp = new Node(val);
		temp->next = head;
		head->prev = temp;
		head = temp;
		size++;
	}
	bool pop_front() {
		if(size == 0)
			return 0;
		if(size == 1) {
			delete head;
			head = tail = NULL;
			size = 0;
			return 1;
		}
		Node *temp = head;
		head = head->next;
		delete temp;
		head->prev = NULL;
		size--;
		return 1;
	}
	void push_back(T val) {
		if(size == 0) {
			head = new Node(val);
			tail = head;
			size++;
			return;
		}
		tail->next = new Node(val);
		tail->next->prev = tail;
		tail = tail->next;
		size++;
	}
	bool pop_back() {
		if(size == 0)
			return 0;
		if(size == 1) {
			delete head;
			head = tail = NULL;
			size = 0;
			return 1;
		}
		Node *temp = tail;
		tail = tail->prev;
		delete temp;
		tail->next = NULL;
		size--;
		return 0;
	}
	bool insert_at(int indx, T val) {
		if(indx < 0 or indx >= size)
			return 0;
		if(indx == 0) {
			push_front(val);
			return 1;
		}
		Node *temp = head;
		for(int i = 0;i < indx - 1;i++) {
			temp = temp->next;
		}
		Node *temp2 = temp->next;
		temp->next = new Node(val);
		temp->next->prev = temp;
		temp = temp->next;
		temp->next = temp2;
		temp2->prev = temp;
		size++;
		return 1;
	}
	void sort_list() {
		Node *cur = head;
		while(cur) {
			Node *temp = cur->next;
			while(temp) {
				if(cur->value > temp->value) {
					std::swap(cur->value, temp->value);
				}
				temp = temp->next;
			}
			cur = cur->next;
		}
	}
	void reverse_list() {
		Node *cur = head;
		while(cur) {
			std::swap(cur->next, cur->prev);
			cur = cur->prev;
		}
		std::swap(head, tail);
	}
	void clear() {
		this->~Linkedlist();
	}
	bool erase(int indx) {
		if(indx < 0 or indx >= size)
			return 0;
		Node *cur = head;
		for(int i = 0;i < indx;i++) {
			cur = cur->next;
		}
		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		delete cur;
		size--;
		return 0;
	}
	bool empty() {
		return size;
	}
	void swap(Linkedlist &otherlist) {
		Linkedlist temp = *this;
		*this = otherlist;
		cerr << this->size;
		otherlist = temp;
	}
	Linkedlist& operator=(Linkedlist &otherlist) {
		Node *cur = head;
		while(cur) {
			Node *temp = cur;
			cur = cur->next;
			delete temp;
		}
		head = tail = NULL;
		size = otherlist.size;
		if(size == 0)
			return otherlist;
		cerr << size;
		head = new Node(otherlist.head->value);
		cur = head;
		Node *other_cur = otherlist.head->next;
		while(other_cur) {
			cur->next = new Node(other_cur->value);
			cur->next->prev = cur;
			cur = cur->next;
			other_cur = other_cur->next;
		}
		tail = cur;
		return otherlist;
	}
	int sz() {
		return size;
	}
	void print() {
		Node *cur = head;
		while(cur) {
			cout << cur->value << ' ' ;
			cur = cur->next;
		}
		cout << endl;
	}
	T operator[](int indx) {
		if(indx < 0 or indx >= size) {
			throw "out_of_range";
		}
		Node *cur = head;
		for(int i = 0;i < indx;i++)
			cur = cur->next;
		return cur->value;
	}
};
#endif
