//노드 최대 개수가 1000이므로 N^2까지 가능

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<bool> visited;
vector<vector<int>> v;

void dfs_stack(int start) {
	stack<int> s;
	s.push(start);
	visited[start] = true;

	while (!s.empty()) {
		int top = s.top();
		s.pop();

		for (int i : v[top]) {
			if (!visited[i]) {
				s.push(i);
				visited[i] = true;
			}
		}
	}
}

void dfs_recursion(int cur) {
	if (visited[cur]) return;
	visited[cur] = true;
	for (int i : v[cur]) {
		if (!visited[i]) {
			dfs_recursion(i);
		}
	}
}

int main() {
  int n, e;
	cin >> n >> e;

	v.resize(n + 1);
	visited = vector<bool>(n + 1, false);
	
	int n1, n2;
	for (int i = 0; i < e; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	
	int cnt = 0;
	for (int start = 1; start <= n; start++) {
		if (!visited[start]) {
			//dfs_stack(start);
			dfs_recursion(start);
			cnt++;
		}
	}

	cout << cnt << '\n';
}
