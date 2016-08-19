int n, dfs_low[101], dfs_num[101], parent[101], dfs_root, dfs_time, childs;
bool adjacency_matrix[101][101];
bool is_articulation_point[101];


void getArticulationPoints(int u) {
	dfs_num[u] = dfs_low[u] = ++dfs_time;
	for(int v = 1;v <= n;v++) {
		if(adjacency_matrix[u][v]) {
			if(dfs_num[v] == 0) {
				parent[v] = u;
				if(u == dfs_root)
					childs++;
				getArticulationPoints(v);
				if(dfs_low[v] >= dfs_num[u]) {
					is_articulation_point[u] = true;
				}
				dfs_low[u] = min(dfs_low[u], dfs_low[v]);
			} else if(v != parent[u]) {
				dfs_low[u] = min(dfs_low[u], dfs_num[v]);
			}
		}
	}
}
