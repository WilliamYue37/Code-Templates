vector<int> manacher(string& orig) {
	string s = "@"; for (char c: orig) s += c, s += '#'; s.back() = '&';
	vector<int> ans(sz(s) - 1);
	int lo = 0, hi = 0;
	for (int i = 1; i < sz(s) - 1; ++i) {
		if (i != 1) ans[i] = min(hi - i, ans[hi - i + lo]);
		while (s[i - ans[i] - 1] == s[i + ans[i] + 1]) ++ans[i];
		if (i + ans[i] > hi) lo = i - ans[i], hi = i + ans[i];
	}
	ans.erase(begin(ans));
	for (int i = 0; i < sz(ans); ++i) if ((i & 1) == (ans[i] & 1)) ++ans[i];
	return ans;
}
