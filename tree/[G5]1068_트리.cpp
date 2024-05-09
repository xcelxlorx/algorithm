#include <iostream>
#include <vector>

using namespace std;

int n, s;
vector<vector<int>> tree;

int dfs(int node) {
	int cnt = 0;
	if (tree[node].size() == 0) cnt++;
	for (int next : tree[node]) cnt += dfs(next);
	return cnt;
}

int main() {
	int node, r; cin >> n;

	tree = vector<vector<int>>(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> node;
		if (node == -1) s = i;
		tree[node + 1].push_back(i);
	}
	
	cin >> r; r++;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < tree[i].size(); j++) {
			if (tree[i][j] == r) {
				tree[i].erase(tree[i].begin() + j);
			}
		}
	}

	if (s == r) cout << 0;
	else cout << dfs(s);
}
