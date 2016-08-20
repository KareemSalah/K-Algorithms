#include <bits/stdc++.h>
using namespace std;

int inf = INT_MAX>>1;
long long linf = 1e18, lninf = -1e18;
long long mod = 1e9+7;
double PI = 3.1415926535897932384626433832795;
double eps = 1e-12;



int n, m, cnt, lo[2003], nm[2003], dfs_time, cnt2;
vector<int> arr[2003], st;
bool stacked[2003];

void tscc(int u) {
	lo[u] = nm[u] = dfs_time++;
	for(auto v : arr[u]) {
		if(nm[v] == 0) {
			st.push_back(v);
			stacked[v] = 1;
			tscc(v);
		}
		if(stacked[v]) {
			lo[u] = min(lo[u], lo[v]);
		}
	}
	if(lo[u] == nm[u]) {
		cnt++;
		while(1) {
			cnt2++;
			int v = st.back();
			stacked[v] = 0;
			st.pop_back();
			if(v == u)
				break;
		}
	}
}





int main() {
	while(scanf("%d %d", &n, &m) and n and m) {
		cnt = cnt2 = 0;
		for(int i = 1;i <= n;i++) {
			arr[i].clear();
		}
		st.clear();
		memset(stacked, 0, sizeof stacked);
		memset(nm, 0, sizeof nm);
		memset(lo, 0, sizeof lo);
		dfs_time = 0;
		for(int i = 0;i < m;i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			arr[a].push_back(b);
			if(c == 2)
				arr[b].push_back(a);
		}
		tscc(1);
		if(cnt == 1 and cnt2 == n)
			puts("1");
		else
			puts("0");
	}
	return 0;
}
