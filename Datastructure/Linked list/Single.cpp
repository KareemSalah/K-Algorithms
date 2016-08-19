#ifndef SINGLE_LINKEDLIST_H_
#define SINGLE_LINKEDLIST_H_
#include <bits/stdc++.h>
using namespace std;

template<class T>
class Linkedlist {
	class Node {
		friend class Linkedlist;
		Node* next;
		T value;
	public:
		Node() {
			next = NULL;
		}
		Node(T val) {
			value = val;
			next = NULL;
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
		while (cur) {
			Node* temp = cur;
			cur = cur->next;
			delete temp;
		}
		head = tail = NULL;
		size = 0;
	}
	Linkedlist(const Linkedlist& otherlist) {
		size = otherlist.size;
		Node *cur = otherlist.head;
		while (cur) {
			push_back(cur->value);
			cur = cur->next;
		}
	}
	void push_front(T val) {
		Node *temp = new Node(val);
		temp->next = head;
		head = temp;
		if (size == 0)
			tail = head;
		size++;
	}
	bool pop_front() {
		if (head == NULL)
			return 0;
		Node *temp = head;
		head = head->next;
		delete temp;
		size--;
		return 1;
	}
	bool insert_at(int indx, T val) {
		if (indx >= size or indx < 0)
			return 0;
		if (indx == 0)
			push_front(val);
		else {
			Node *cur = head, *post_cur = head->next;
			for (int i = 0; i < indx - 1; i++) {
				cur = post_cur;
				post_cur = post_cur->next;
			}
			Node *temp = new Node(val);
			temp->next = post_cur;
			cur->next = temp;
			size++;
		}
		return 0;
	}
	void push_back(T val) {
		if (head == NULL) {
			head = new Node(val);
			tail = head;
			size++;
			return;
		}
		tail->next = new Node(val);
		tail = tail->next;
		size++;
	}
	bool pop_back() {
		if (size == 0)
			return 0;
		if (size == 1) {
			delete head;
			head = tail = NULL;
			size = 0;
			return 1;
		}
		Node *cur = head, *post_cur = head->next;
		while (post_cur->next != NULL) {
			cur = post_cur;
			post_cur = post_cur->next;
		}
		delete post_cur;
		tail = cur;
		tail->next = NULL;
		size--;
		return 1;
	}
	void sort_list() {
		Node * cur = head;
		while (cur) {
			T temp_v = cur->value;
			Node *temp_nd, *post_cur = cur->next;
			while (post_cur) {
				if (post_cur->value < temp_v) {
					temp_v = post_cur->value;
					temp_nd = post_cur;
				}
				post_cur = post_cur->next;
			}
			std::swap(cur->value, temp_nd->value);
			cur = cur->next;
		}
	}
	void reverse_list() {
		if (size <= 1) {
			std::swap(head, tail);
			return;
		}
		Node *cur = head, *post_cur = head->next;
		while (post_cur) {
			Node *temp = post_cur->next;
			post_cur->next = cur;
			cur = post_cur;
			post_cur = temp;
		}
		std::swap(head, tail);
		tail->next = NULL;
	}
	void clear() {
		this->~Linkedlist();
	}
	bool erase(int indx) {
		if (indx < 0 or indx >= size)
			return 0;
		if (indx == 0)
			pop_front();
		else if (indx == size - 1)
			pop_back();
		else {
			Node *cur = head, *post_cur = head->next;
			for (int i = 0; i < indx - 1; i++) {
				cur = post_cur;
				post_cur = post_cur->next;
			}
			cur->next = post_cur->next;
			delete post_cur;
			size--;
		}
		return 1;
	}
	bool empty() {
		return head == NULL;
	}
	void swap(Linkedlist& anotherlist) {
		Linkedlist temp_list = *this;
		*this = anotherlist;
		anotherlist = temp_list;
	}
	Linkedlist& operator=(Linkedlist& otherlist) {
		this->~Linkedlist();
		size = otherlist.size;
		Node *cur, *other_cur = otherlist.head->next;
		head = new Node(otherlist.head->value);
		cur = head;
		while (other_cur) {
			cur->next = new Node(other_cur->value);
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
		while (cur) {
			cout << cur->value << ' ';
			cur = cur->next;
		}
		cout << endl;
	}
	T operator[](int indx) {
		if(indx < 0 or indx >= sz) {
			throw "out_of_range";
		}
		Node *cur = head;
		for(int i = 0;i < indx;i++) {
			cur = cur->next;
		}
		return cur->value;
	}
};
#endif
