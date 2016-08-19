#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int *arr, int n, int step = 1) {
	for (int i = 0; i + step < n; i++) {
		for (int j = i + step; j < n; j += step) {
			int tmp = j;
			while (arr[tmp] < arr[tmp - step]) {
				swap(arr[tmp], arr[tmp - step]);
				tmp -= step;
			}
		}
	}
	return ;
}

void shell_sort_this_array_please_using_these_gaps(int *arr, int n, int *gaps, int m) {
	for (int i = 0; i < m; i++)
		insertion_sort(arr, n, gaps[i]);
	return;
}

int main() {
	int gaps[] = { 5, 3, 1 }, m = 3, arr[] = { 1, 0, 2, 9, 6, 4, 3, 8, 5, 2 },
			n = 10;
	shell_sort_this_array_please_using_these_gaps(arr, n, gaps, m);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}