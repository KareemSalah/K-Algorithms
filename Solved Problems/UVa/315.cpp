#include <bits/stdc++.h>
using namespace std;

int inf = INT_MAX>>1;
long long linf = 1e18, lninf = -1e18;
long long mod = 1e9+7;
double PI = 3.1415926535897932384626433832795;
double eps = 1e-12;



int n, lo[101], nm[101], par[101], dfs_root, dfs_time, childs;
bool arr[101][101];
bool is_ap[101];


void ap(int u) {
	nm[u] = lo[u] = ++dfs_time;
	for(int v = 1;v <= n;v++) {
		if(arr[u][v]) {
			if(nm[v] == 0) {
				par[v] = u;
				if(u == dfs_root)
					childs++;
				ap(v);
				if(lo[v] >= nm[u]) {
					is_ap[u] = 1;
				}
				lo[u] = min(lo[u], lo[v]);
			} else if(v != par[u]) {
				lo[u] = min(lo[u], nm[v]);
			}
		}
	}
}


int main() {
	bool ln = 0;
	while(cin >> n and n) {
		for(int i = 1;i <= n;i++) {
			lo[i] = nm[i] = 0;
		}
		memset(arr, 0, sizeof arr);
		memset(nm, 0, sizeof nm);
		memset(lo, 0, sizeof lo);
		memset(is_ap, 0, sizeof is_ap);
		memset(par, 0, sizeof par);
		string s;
		stringstream ss;
		while(getline(cin, s)) {
			if(s[0] == '0')
				break;
			ss << s;
			int u, v;
			ss >> u;
			while(ss >> v) {
				arr[u][v] = arr[v][u] = 1;
			}
			ss.clear();
		}
		int ans = 0;
		for(int u = 1;u <= n;u++) {
			if(nm[u] == 0) {
				childs = 0;
				dfs_root = u;
				ap(u);
				is_ap[u] = childs > 1;
			}
			ans += is_ap[u];
		}
		cout << ans << '\n';
		ln = 1;
	}
	return 0;
}
