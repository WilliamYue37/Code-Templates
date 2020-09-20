int parent[MAX_N], subtreeSize[MAX_N];
bool blocked[MAX_N];
queue<int> q;

void calcSize(int u, int p) {
	parent[u] = p;
	subtreeSize[u] = 1;

	for (pi e: adj[u]) {
		if (e.ff != p && !blocked[e.ff]) {
			calcSize(e.ff, u);
			subtreeSize[u] += subtreeSize[e.ff];
		}
	}
}

ll solveTree(int root) {
	return 0;
}

ll go(int entryPoint) {
	calcSize(entryPoint, entryPoint);

	int centroid = entryPoint;
	int bestSize = subtreeSize[entryPoint];

	q.push(entryPoint);
	while (!q.empty()) {
		int u = q.front(); q.pop();

		int size = subtreeSize[entryPoint] - subtreeSize[u];

		for (pi e: adj[u]) {
			if (e.ff != parent[u] && !blocked[e.ff]) {
				size = max(size, subtreeSize[e.ff]);
				q.push(e.ff);
			}
		}

		if (size < bestSize) {
			centroid = u;
			bestSize = size;
		}
	}

	ll ways = solveTree(centroid);

	blocked[centroid] = true;
	for (pi e: adj[centroid]) {
		if (!blocked[e.ff]) {
			ways += go(e.ff);
		}
	}

	return ways;
}
