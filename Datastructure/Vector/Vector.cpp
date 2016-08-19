#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Vec {
private:
	int *arr, _size, _capacity;
	void copy(int * from, int * to, int size) {
		for (int i = 0; i < size; i++) {
			to[i] = from[i];
		}
	}
public:
	void clear() {
		delete[] arr;
		_size = _capacity = 0;
		arr = NULL;
	}
	T* begin() {
		return arr;
	}
	T* end() {
		return arr + _size;
	}
	T front() {
		return arr[0];
	}
	T back() {
		return arr[_size - 1];
	}
	void pb(T t) {
		if (_size == _capacity) {
			int *cpy = new int[2 * _size];
			copy(arr, cpy, _size);
			cpy[_size] = t;
			delete[] arr;
			arr = cpy;
			_capacity *= 2;
		}
		arr[_size++] = t;
	}
	void pf(T t) {
		if (_size == _capacity) {
			int *cpy = new int[2 * _size];
			copy(arr, cpy + 1, _size);
			arr = cpy;
			_capacity *= 2;
		} else {
			for (int i = _size; i > 0; i--) {
				arr[i] = arr[i - 1];
			}
		}
		_size++;
		arr[0] = t;
	}
	void insert(T t, int indx) {
		if (_size == _capacity) {
			int *cpy = new int[2 * _size];
			copy(arr, cpy, _size);
			delete[] arr;
			arr = cpy;
		}
		for (int i = _size; i > indx; i--)
			arr[i] = arr[i - 1];
		arr[indx] = t;
		_size++;
	}
	Vec() :
			arr(NULL), _size(0), _capacity(0) {
	}
	Vec(int size) : _size(size), _capacity(size) {
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = 0;
	}
	Vec(int size, T val) : _size(size), _capacity(size) {
		arr = new int[size];
		for(int i = 0;i < size;i++)
			arr[i] = val;
	}
	Vec(T* first, T*last) {
		_size = _capacity = last - first;
		arr = new int[_size];
		for(int i = 0;i < _size;i++)
			arr[i] = *(first+i);
	}
	Vec(Vec<T>& otherVec) {
		_size = otherVec._size;
		_capacity = otherVec._capacity;
		arr = new int[otherVec._capacity];
		copy(otherVec.arr, arr, otherVec._size);
	}
	T& operator[](int indx) {
		if (indx >= _size or indx < 0) {
			throw 3;
		} else {
			return arr[indx];
		}
	}
	Vec& operator=(Vec & otherVec) {
		_size = otherVec._size;
		_capacity = otherVec._capacity;
		if(arr == NULL)
			delete[] arr;
		arr = new int[otherVec._capacity];
		copy(otherVec.arr, arr, otherVec._size);
		return *this;
	}
	int popb() {
		if (_size == 0) {
			throw 1;
		} else {
			T tmp = arr[_size - 1];
			_size--;
			return tmp;
		}
	}
	T popf() {
		if (_size == 0) {
			throw 2;
		} else {
			T tmp = arr[0];
			for (int i = 0; i < _size - 1; i++)
				arr[i] = arr[i + 1];
			_size--;
			return tmp;
		}
	}
	int size() {
		return _size;
	}
	int capacity() {
		return _capacity;
	}
	int erase(int indx) {
		if (indx >= _size or indx < 0) {
			throw 4;
		} else {
			T tmp = arr[indx];
			for (int i = indx; i < _size - 1; i++) {
				arr[i] = arr[i + 1];
			}
			_size--;
			return tmp;
		}
	}
	~Vec() {
		delete[] arr;
	}
};