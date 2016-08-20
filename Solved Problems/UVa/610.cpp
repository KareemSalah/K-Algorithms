#include <bits/stdc++.h>
using namespace std;

int inf = INT_MAX>>1;
long long linf = 1e18, lninf = -1e18;
long long mod = 1e9+7;
double PI = 3.1415926535897932384626433832795;
double eps = 1e-12;


int n, m;
vector<int> arr[1003];
vector<pair<int, int> >edges;
int dfs_time, lo[1003], nm[1003], par[1003];
bool vis[1003][1003];

void ap(int u) {
	lo[u] = nm[u] = dfs_time++;
	for(auto v : arr[u]) {
		if(!vis[u][v]) {
			edges.push_back({u, v});
		}
		vis[u][v] = vis[v][u] = 1;
		if(nm[v] == 0) {
			par[v] = u;
			ap(v);
			if(lo[v] > nm[u]) {
				edges.push_back({v, u});
			}
			lo[u] = min(lo[u], lo[v]);
		} else {
			if(v != par[u]) {
				lo[u] = min(lo[u], nm[v]);
			}
		}
	}
}


int main() {
	int cas = 1;
	while(scanf("%d %d", &n, &m) and n and m) {
		printf("%d\n\n", cas++);
		edges.clear();
		dfs_time = 1;
		memset(vis, 0, sizeof vis);
		memset(lo, 0, sizeof lo);
		memset(nm, 0, sizeof nm);
		memset(par, 0, sizeof par);
		for(int i = 1;i <= n;i++) {
			arr[i].clear();
		}
		for(int i = 0;i < m;i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			arr[b].push_back(a);
			arr[a].push_back(b);
		}
		ap(1);
		for(auto pi : edges) {
			printf("%d %d\n", pi.first, pi.second);
		}
		puts("#");
	}
	return 0;
}
