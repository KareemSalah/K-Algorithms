//Dynamic Programming, O(N), Maximum Contiguous Subarray
//Given an array of N elements of positive integers, zeros, and possibly negatives, find the largest continguous subarray that has the maximum summation.
//This is a simple dynamic programming problem, the algorithms has two variations, if the problem statment allows empty subarray, or if it doesn't, check the code for the both variations.
//The algorithm goes as follows, for each element, the algorithm computes the maximum subarray ending at that element, maximizing the best sum while looping over the array elements.
//There are some questions i was asking myself, what if the array is like arr[1, -1] or like arr[2, -1, 1, -2], in other words, what if the positive elements sum is equal to the negative numbers sum? the algorithm works because at some point, the sum has to be positive before adding the last negative value that makes the total sum is equal to zero, while looping over the array and maximizing the sum on the way, that poing will be reached and saved as a max result.
//the overlapping sub-structures are the summations already calculated while looping over the array
//to me: it's like,in the case of positive and negative elements catching the first positive value and that will be my peak, memorize it, and add the next value, if greater, then a new peak is achieved, keep doing that until the sumation is negative, if it's negative, then reset the summation to 0 and start again but from the next index(the one after the current one that made my summation negative) and i still have my peak, suppose it's like that [2, 3, -6, x] at -6 the summation will be negative, so if x is like 200, then i won't have to get back and check of i can add other elements before 200 that will increase the sum, the previous elements contribute negatively so i just don't have to include them in the new sum, just start from the 200, but in this case [3, 3, -6, 1, x], taking the numbers before x will contribute with a total of 1 if including x in the solution so i'll consider it and check on x, i keep maximizing the answers i have until i reach the end of the array, another variation is when all the elements are negative and i do not allow empty sub array, i just don't maximize against zero, i maximize between the current sum added to the current element or the current element only, like this "should i choose this element alone and start from it and ignore the previous sum or should i add it to the previous sum? the better of them i will add it the next values comming on", and keep maximizing untill the loop ends, that's how the algorithm works.


//C++ implementation
#include <bits/stdc++.h>
using namespace std;
//My array and the size
int arr[] = {1, 2, -2, 3, -7 , 19, 0, -8}, sz = 8;
//A version of the algorithm that returns the value of the maximum subarray
int max_subarr() {
	//declaring 2 variables to store the result, and the max summation of subarray ending at each element, notice that current_sum is set to zero because empty subarrays are allowed
	int best_sum = 0, current_sum = 0;
	for(int i = 0; i < sz ; i++) {
		//check if adding this element to the subarray (consider it the last element in the subarray) will maxmize the contribution to the sum, if so, then add it to the current sum of subarray, if not, it means that the subarray sum is negative, start from zero
		current_sum = max(0, current_sum + arr[i]);
		//if the current subarray summation is the greatest so far, store it in best_sum
		best_sum = max(best_sum, current_sum);
	}
	//if the problem doesn't allow empty subarrays, then i set the initial value for current_sum to the first element of the array, and start looping from the 2nd element in the array
	/*best_sum = current_sum = arr[0];
	for(int i = 1; i < sz ; i++) {
		//if adding the current element to the subarray summation will make it greater, then i'll add it, if not, then i'll start a new subarray starting from this element
		current_sum = max(arr[i], current_sum + arr[i]);
		//updating the answer
		best_sum = max(best_sum, current_sum);
	}*/

	//return the maximum sum so far
	return best_sum;
}


//Another version for getting the indices of the greates sum subarray, indices will be stored in 2 parameters passed by reference
void max_subarr2(int &a, int &b) {
	//declaring a variable to keep track of the greates sum, another one for summing the values of the current subarray, and a third one to keep track of the beginning of the subarray
	// int best_sum, current_sum, current_start_index;
	// //first variation, if empty subarrays are allowed, then initialize all variables to 0 except for the start index, let it -1;
	// best_sum = 0, current_sum = 0, current_start_index = -1;
	// //incase of no solutions available, like all numbers are negative
	// a = b = -1;
	// for(int i = 0 ; i < sz ; i++) {
	// 	//check if adding this element will produce a positive summation
	// 	if(current_sum + arr[i] >= 0) {
	// 		//if so, then check if this element is the beginning of the subarray, if so..mark this index in current_start_index
	// 		if(current_sum == 0)
	// 			current_start_index = i;
	// 		//update the subarray sum
	// 		current_sum += arr[i];
	// 	}
	// 	else //if this will not contribute in my sum, start over again
	// 		current_sum = 0;
	// 	//if i have another answer that is greater that the one i have, then update the best_sum, and also update the indices of the beginning and the end
	// 	if(current_sum > best_sum) {
	// 		a = current_start_index;
	// 		b = i;
	// 		best_sum = current_sum;
	// 	}
	// }

	// //Another variation, if the problem doesn't allow empty subarray, then set the best sum and the current one the first element in the array, so that i can compare later in the loop
	// best_sum = current_sum = arr[0];
	// //also mark the beginning and ending indices of the answer
	// a = b = current_start_index = 0;
	// //start looping from the 2nd element
	// for(int i = 1; i < sz ; i++) {
	// 	//check if adding this element will lead to greater summation instead of taking a new subarray which start is this element
	// 	if(current_sum + arr[i] > arr[i]) {
	// 		//then update the summation
	// 		current_sum += arr[i];
	// 	}
	// 	else {
	// 		//then it's better to start a new subarray from this element, update the summation and mark the beginning index
	// 		current_sum = arr[i];
	// 		current_start_index = i;
	// 	}
	// 	//whenever i have an answer, i just update the best summation and the indices
	// 	if(current_sum > best_sum) {
	// 		a = current_start_index;
	// 		b = i;
	// 		best_sum = current_sum;
	// 	}
	// }
	return ;
}



//A program to drive the above function
int main() {
	cout << max_subarr();	
	return 0;
}
