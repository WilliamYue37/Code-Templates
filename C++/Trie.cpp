int trie[MAX_N][26], cnt = 1;

void insert(string s) {
	int cur = 0;
	for (char c: s) {
		if (trie[cur][c - 'a'] == 0) trie[cur][c - 'a'] = cnt++;
		cur = trie[cur][c - 'a'];
	}
}
