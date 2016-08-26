#include <bits/stdc++.h>
using namespace std;

int inf = INT_MAX>>1;
long long linf = 1e18, lninf = -1e18;
long long mod = 1e9+7;
double PI = 3.1415926535897932384626433832795;
double eps = 1e-12;





int busy[202];
int dist[202];
bool cyc[202];
vector<pair<int, int> >g[202];


void dfs(int u) {
	cyc[u] = 0;
	for(auto v : g[u]) {
		if(cyc[v.first])
			dfs(v.first);
	}
}


int main() {
	int cas = 1, n;
	while(scanf("%d", &n)) {
		for(int i = 1;i <= n;i++) {
			scanf("%d", busy + i);
			g[i].clear();
			dist[i] = inf;
			cyc[i] = 1;
		}

		int m;
		scanf("%d", &m);
		while(m--) {
			int a, b;
			scanf("%d %d", &a, &b);
			g[a].push_back({b, (busy[b] - busy[a])*(busy[b] - busy[a])*(busy[b] - busy[a])});
		}
		//finding reachable nodes from
		dfs(1);
		//Bellman Ford
		dist[1] = 0;
		for(int i = 0;i < n - 1;i++) {
			for(int u = 1;u <= n;u++) {
				for(auto v : g[u]) {
					if(dist[v.first] > dist[u] + v.second) {
						dist[v.first] = dist[u] + v.second;
					}
				}
			}
		}
		//marking nodes in negative cycles
		for(int i = 0;i < n - 1;i++) {
			for(int u = 1;u <= n;u++) {
				for(auto v : g[u]) {
					if(dist[v.first] > dist[u] + v.second) {
						dist[v.first] = dist[u] + v.second;
						cyc[v.first] = 1;
					}
				}
			}
		}
		int q;
		scanf("%d", &q);
		printf("Set #%d\n", cas++);
		while(q--) {
			int to;
			scanf("%d", &to);
			if(dist[to] < 3 or cyc[to])
				puts("?");
			else {
				printf("%d\n", dist[to]);
			}
		}
	}
	return 0;
}
