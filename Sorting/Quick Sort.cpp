#include <bits/stdc++.h>
using namespace std;
int n = 11;

int partition(int *arr, int l, int r) {
	int pivot = r, pos = 0;
	while(pos < pivot) {
		if(arr[pos] >= arr[pivot]) {
			swap(arr[pos], arr[pivot - 1]);
			swap(arr[pivot - 1], arr[pivot]);
			pivot--;
		}
		else
			pos++;
	}
	return pivot;
}
void quick_sort(int *arr, int l, int r) {
	if(r - l > 1) {
		int pivot = partition(arr, l, r);
		quick_sort(arr, l, pivot - 1);
		quick_sort(arr, pivot + 1, r);
	}
}
int main() {
	int arr[] = {2,5,9,7,3,1,3,4,0,4,9};
	quick_sort(arr, 0, n - 1);
	for(int i = 0;i < n;i++) {
		cout << arr[i] << ' ' ;
	}
	cout << endl;
	return 0;
}
