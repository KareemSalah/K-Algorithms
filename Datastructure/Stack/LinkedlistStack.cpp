#ifndef LINKEDLIST_STACK_H_
#define LINKEDLIST_STACK_H_
#include <bits/stdc++.h>
using namespace std;
template<class T>
class Stack {
	class Node {
		friend class Stack;
		Node *next, *prev;
		T value;
	public:
		Node() {
			next = prev = NULL;
		}
		Node(T val) {
			next = prev = NULL;
			value = val;
		}
	};
	Node *head, *tail;
	int sz;
public:
	Stack() {
		head = tail = 0;
		sz = 0;
	}
	~Stack() {
		sz = 0;
		Node *cur = head;
		while(cur) {
			Node *temp = cur;
			cur = cur->next;
			delete temp;
		}
		head = tail = NULL;
	}
	void push(T val) {
		if(sz == 0) {
			head = new Node(val);
			tail = head;
		}
		else {
			tail->next = new Node(val);
			tail->next->prev = tail;
			tail = tail->next;
		}
		sz++;
	}
	bool pop() {
		if(sz == 0)
			return 0;
		if(sz == 1) {
			delete head;
			head = tail = NULL;
		}
		else {
			tail = tail->prev;
			delete tail->next;
			tail->next = NULL;
		}
		sz--;
		return 1;
	}
	int size() {
		return sz;
	}
	T top() {
		return tail->value;
	}
	bool empty() {
		return !sz;
	}
	void clear() {
		this->~Stack();
	}
	T operator[](int indx) {
		if(indx < 0 or indx >= sz)
			throw "out_of_range";
		Node *cur = head;
		for(int i = 0;i < indx;i++) {
			cur = cur->next;
		}
		return cur->value;
	}
};
#endif
