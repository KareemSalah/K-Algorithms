#include <bits/stdc++.h>
// #include <cstdio>
// #include <iostream>
using namespace std;





//This segment tree solves the problem here http://www.spoj.com/problems/MULTQ3/

/*There are N numbers a[0],a[1]..a[N - 1]. Initally all are 0. You have to perform two types of operations :

1) Increase the numbers between indices A and B (inclusive) by 1. This is represented by the command "0 A B"
2) Answer how many numbers between indices A and B (inclusive) are divisible by 3. This is represented by the command "1 A B".

Input :
The first line contains two integers, N and Q. Each of the next Q lines are either of the form "0 A B" or "1 A B" as mentioned above.

Output :
Output 1 line for each of the queries of the form "1 A B" containing the required answer for the corresponding query.

Sample Input :
4 7
1 0 3
0 1 2
0 1 3
1 0 0
0 0 3
1 3 3
1 0 3

Sample Output :
4
1
0
2

Constraints :
1 <= N <= 100000
1 <= Q <= 100000
0 <= A <= B <= N - 1
*/


struct FastRead {
    char *buff, *ptr;
    FastRead(int size) {
        buff = new char[size];
        ptr = buff;
        fread(buff, size, 1, stdin);
    }
    ~FastRead() {
        delete[] buff;
    }
    inline int nextInt() {
        int ret = 0;
        while(*ptr < '0' || *ptr > '9') ptr++;
        do { ret = ret * 10 + *ptr++ - '0';
        } while(*ptr >= '0' && *ptr <= '9');
        return ret;
    }
};



int arr[100005], n, q;

struct Node {
	int l, r, rem[3], cnt;
	bool lazy;
	Node *left, *right;
	Node(int ll, int rr, bool lazyy, Node *leftt, Node *rightt) {
		l = ll;
		r = rr;
		rem[0] = rem[1] = rem[2] = cnt = 0;
		lazy = lazyy;
		left = leftt;
		right = rightt;
	}
	Node() {
		l = r = rem[0] = rem[1] = rem[2] = lazy = 0;
		left = right = 0;
	}
}*tree;


void rot(Node *node) {
	int tmp = node->rem[2];
	node->rem[2] = node->rem[1];
	node->rem[1] = node->rem[0];
	node->rem[0] = tmp;
		// node->rem[1] = node->rem[0];
		// node->rem[2] = node->rem[1];
		// node->rem[0] = tmp;
}


void build(Node *node, int l, int r) {
	if(l == r) {
		node->rem[0] = 1;
		return ;
	}
	node->left = new Node(l, l + (r - l)/2, 0, 0, 0);
	node->right = new Node(l + (r - l)/2+1, r, 0, 0, 0);
	build(node->left, l, l + (r - l)/2);
	build(node->right, l + (r - l)/2+1, r);
	node->rem[0] = node->left->rem[0] + node->right->rem[0];
	return;
}

void push(Node *node) {
	if(node->lazy) {
		node->lazy = 0;
		int tmp = node->cnt % 3;
		while(tmp--)
			rot(node);
		if(node->left != NULL) {
			node->left->lazy = 1;
			node->left->cnt += node->cnt;
		}
		// node->left->cnt = node->cnt;
		if(node->right != NULL) {
			node->right->lazy = 1;
			node->right->cnt += node->cnt;
		}// node->right->cnt = node->cnt;
		node->cnt = 0;
	}
}


int getMax(Node *node, int l, int r) {
	push(node);
	int ll = node->l, rr = node->r;
	if(rr < l or ll > r)
		return 0;
	if(ll >= l and rr <= r) {
		return node->rem[0];
	}
	return getMax(node->left, l, r) + getMax(node->right, l, r);
}

void update(Node *node, int l, int r) {
	int ll = node->l, rr = node->r;
	push(node);
	if(rr < l or ll > r)
		return;
	if(ll >= l and rr <= r) {
		node->lazy = 1;
		node->cnt++;
		// rot(node);
		push(node);
		return;
	}
	update(node->left, l, r);
	update(node->right, l, r);
	node->rem[0] = node->left->rem[0] + node->right->rem[0];
	node->rem[1] = node->left->rem[1] + node->right->rem[1];
	node->rem[2] = node->left->rem[2] + node->right->rem[2];
}



int main() {
	// ios::sync_with_stdio(false);
	// cin >> n >> q;
	// scanf("%d%d", &n, &q);
	// n = readInt();
	// q = readInt();
	FastRead fr(4194304);
	n = fr.nextInt();
	q = fr.nextInt();
	tree = new Node(0, n - 1, 0, NULL, NULL);
	build(tree, 0, n - 1);
	// print(tree);
	while(q--) {
		int t, a, b;
		// cin >> t >> a >> b;
		// scanf("%d%d%d", &t, &a, &b);
		// t = readInt();
		// a = readInt();
		// b = readInt();
		t = fr.nextInt();
		a = fr.nextInt();
		b = fr.nextInt();
		if(t) {
			printf("%d\n", getMax(tree, a, b));
		} else {
			update(tree, a, b);
			// print(tree);
		}
	}
	return 0;
}