//촌수는 한 노드에서 다른 노드로 가기 위한 엣지의 개수
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<int> depth;

void dfs(int cur) {
	for (int e : v[cur]) {
		if (!depth[e]) {
			depth[e] = depth[cur] + 1;
			dfs(e);
		}
	}
}

int main() {
	int n, num1, num2, m; cin >> n >> num1 >> num2 >> m;
	
	v.resize(n + 1);
	depth = vector<int>(n + 1, false);

	while (m--) {
		int parent, child;
		cin >> parent >> child;
		v[parent].push_back(child);
		v[child].push_back(parent);
	}

	dfs(num1);

	int answer = depth[num2] == 0 ? -1 : depth[num2];
	cout << answer;
}
