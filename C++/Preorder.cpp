pi range[MAX_N];

int id = 0;
void preorder(int u, int p) {
	range[u].ff = id++;
	for (int v: adj[u]) {
		if (v != p) preorder(v, u);
	}
	range[u].ss = id - 1;
}
