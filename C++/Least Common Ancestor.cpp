int depth[MAX_N], parent[MAX_N][MAX_LOG]; // must be 1-indexed, the parent of the root is 0

void DFS(int u, int p, int d) {
	depth[u] = d; parent[u][0] = p;
	for (int v: adj[u]) {
		if (v != p) DFS(v, u, d + 1);
	}
}

void LCA_precompute() {
	DFS(1, 0, 0);
	for (int k = 1; k < MAX_LOG; ++k) {
		for (int i = 1; i <= N; ++i) {
			parent[i][k] = parent[parent[i][k - 1]][k - 1];
		}
	}
}

int lift(int u, int h) {
	for (int i = 0; (1 << i) <= h; ++i) {
		if ((h & (1 << i)) != 0) {
			u = parent[u][i];
		}
	}
	return u;
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) {
		b = lift(b, depth[b] - depth[a]);
	}
	else if (depth[b] < depth[a]) {
		a = lift(a, depth[a] - depth[b]);
	}
	if (a == b) return a;
	for (int k = MAX_LOG - 1; k >= 0; --k) {
		if (parent[a][k] != parent[b][k]) {
			a = parent[a][k], b = parent[b][k];
		}
	}
	return parent[a][0];
}

int dist(int a, int b) {
	int lca = LCA(a, b);
	return depth[a] + depth[b] - 2 * depth[lca];
}
