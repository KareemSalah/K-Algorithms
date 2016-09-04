#include <bits/stdc++.h>
//#include <vector>
//#include <iostream>
//#include <string>
//#include <limits.h>
//#include <queue>
//#include <set>
//#include <map>
//#include <algorithm>
using namespace std;

int inf = INT_MAX>>1;
long long linf = 1e18, lninf = -1e18;
long long mod = 1e9+7;
double PI = 3.1415926535897932384626433832795;
double eps = 1e-12;


int n, m;
vector<int> g[100005], component[100005];
vector<int>ans;
bool stacked[100005], vis[100005];
int nm[100005], lo[100005], cmpIdx[100005], col[100005], path[100005], scc[100005], cpath, cscc;
int dfs_time, cmpCnt, start, target;
bool done, stop;


void init() {
	for(int i = 0;i < n;i++) {
		g[i].clear();
		component[i].clear();
		stacked[i] = vis[i] = 0;
		nm[i] = lo[i] = cmpIdx[i] = 0;
		col[i] = -1;
	}
	cpath = cscc = 0;
	done = stop = 0;
	dfs_time = cmpCnt = 1;
}


void tscc(int u) {
	lo[u] = nm[u] = dfs_time++;
	for(auto v : g[u]) {
		if(nm[v] == 0) {
			scc[cscc++] = v;
			stacked[v] = 1;
			tscc(v);
		}
		if(stacked[v]) {
			lo[u] = min(lo[u], lo[v]);
		}
	}
	if(lo[u] == nm[u]) {
		while(1) {
			int v = scc[cscc-1];
			cmpIdx[v] = cmpCnt;
			stacked[v] = 0;
			cscc--;
			if(v == u) {
				break;
			}
		}
		cmpCnt++;
	}
}


void color(int u, int clr) {
	col[u] = clr;
	for(auto v : g[u]) {
		if(done)
			return;
		if(col[v] == -1 and cmpIdx[v] == cmpIdx[u]) {
			color(v, 1 - clr);
		} else if(col[v] == col[u] and cmpIdx[v] == cmpIdx[u]) {
			start = v;
			target = u;
			done = 1;
			return;
		}
	}
}




void dfs2(int u) {
	path[cpath++] = u;
	vis[u] = 1;
	if(u == target) {
		stop = 1;
		return ;
	}
	for(auto v : g[u]) {
		if(!vis[v] and col[v] != -1 and col[v] != col[u])
			dfs2(v);
		if(stop)
			return ;
	}
	cpath--;
}




int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		init();
		for(int i = 0;i < m;i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			g[u-1].push_back(v-1);
		}

		for(int i = 0;i < n;i++) {
			if(cmpIdx[i] == 0) {
				scc[cscc++] = i;
				stacked[i] = 1;
				tscc(i);
			}
		}

		for(int i = 0;i < n;i++) {
			if(cmpIdx[i] != 0) {
				component[cmpIdx[i]].push_back(i);
			}
		}

		for(int i = 1;i < cmpCnt and !done;i++) {
			if(component[i].size()) {
				color(component[i][0], 0);
			}
		}

		if(!done) {
			puts("-1");
			continue;
		}
		dfs2(start);


		while(cpath--) {
			ans.push_back(path[cpath]);
		}
		printf("1\n%d\n", (int)ans.size());
		reverse(ans.begin(), ans.end());
		for(auto i : ans) {
			printf("%d\n", i+1);
		}
	}
	return 0;
}
