#ifndef ARRAY_STACK_H_
#define ARRAY_STACK_H_
#include <bits/stdc++.h>
using namespace std;

template<class T>
class Stack {
	T *arr;
	int sz, capacity;
	void expand(int newsz) {
		T *temp = new T[newsz];
		for(int i = 0;i < min(sz, newsz);i++) {
			temp[i] = arr[i];
		}
		if(sz)
			delete[] arr;
		arr = temp;
		capacity = newsz;
	}
public:
	Stack() {
		arr = NULL;
		sz = capacity = 0;
	}
	Stack(int sz2, T val) {
		arr = new T[sz2];
		for(int i = 0;i < sz2;i++)
			arr[i] = val;
		sz = sz2;
		capacity = sz;
	}
	~Stack() {
		if(sz == 0)
			return ;
		delete[] arr;
		sz = capacity = 0;
		arr = NULL;
	}
	Stack(const Stack &otherstack) {
		sz = otherstack.sz;
		capacity = otherstack.capacity;
		arr = new T[capacity];
		for(int i = 0;i < sz;i++) {
			arr[i] = otherstack.arr[i];
		}
	}
	void push(T val) {
		if(sz == capacity) {
			if(sz == 0)
				expand(1);
			else
				expand(capacity*2);
		}
		arr[sz] = val;
		sz++;
	}
	bool pop() {
		if(sz == 0)
			return 0;
		sz--;
		return 1;
	}
	T top() {
		return arr[sz - 1];
	}
	int size() {
		return sz;
	}
	void clear() {
		if(sz != 0)
			delete[] arr;
		sz = 0;
	}
	bool empty() {
		return !sz;
	}
	T operator[](int indx) {
		if(indx < 0 or indx >= sz)
			throw "out_of_rang";
		return arr[indx];
	}
};
#endif
