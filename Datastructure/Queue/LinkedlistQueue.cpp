#ifndef LINKEDLIST_QUEUE_H_
#define LINKEDLIST_QUEUE_H_
#include <bits/stdc++.h>
using namespace std;

template<class T>
class Queue {
	class Node {
		friend class Queue;
		Node * next, *prev;
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
	Node * head, *tail;
	int size;
public:
	Queue() {
		head = tail = NULL;
		size = 0;
	}
	Queue(const Queue& otherqueue) {
		size = otherqueue.size;
		if (size == 0) {
			head = tail = NULL;
			return;
		}
		head = new Node(otherqueue.head->value);
		Node *cur = head, *other_cur = otherqueue.head->next;
		while (other_cur) {
			cur->next = new Node(other_cur->value);
			cur = cur->next;
			other_cur = other_cur->next;
		}
		tail = cur;
	}
	~Queue() {
		if (size == 0)
			return;
		Node *cur = head;
		while (cur) {
			Node *temp = cur;
			cur = cur->next;
			delete temp;
		}
		size = 0;
	}
	void push(T val) {
		if (size == 0) {
			head = new Node(val);
			tail = head;
		} else {
			tail->next = new Node(val);
			tail = tail->next;
		}
		size++;
	}
	bool pop() {
		if (size == 0)
			return 0;
		Node *temp = head;
		head = head->next;
		delete temp;
		size--;
		return 1;
	}
	bool empty() {
		return !size;
	}
	int sz() {
		return size;
	}
	T top() {
		if (size)
			return head->value;
		throw "empty_queue";
	}
	T back() {
		if (size)
			return tail->value;
		throw "empty_queue";
	}
	void print() {
		Node *cur = head;
		while (cur) {
			cout << cur->value << ' ';
			cur = cur->next;
		}
		cout << endl;
	}
	Queue& operator=(Queue& otherqueue) {
		size = otherqueue.size;
		if (size == 0) {
			head = tail = NULL;
			return otherqueue;
		}
		this->~Queue();
		head = new Node(otherqueue.head->value);
		Node *cur = head, *other_cur = otherqueue.head->next;
		while (other_cur) {
			cur->next = new Node(other_cur->value);
			cur = cur->next;
			other_cur = other_cur->next;
		}
		tail = cur;
		return otherqueue;
	}
};

#endif
