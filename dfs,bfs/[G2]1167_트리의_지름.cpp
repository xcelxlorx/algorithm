/*
트리의 지름 구하기
1. A에서 가장 먼 점 B를 찾음
2. B에서 가장 먼 점 C를 찾음
3. BC가 트리의 지름
참고 : https://jioneprogstdy.tistory.com/77
*/

/*
for문으로 모든 노드를 확인하면 N^2라서 시간초과 발생
시작 정점에 따라 지름이 다르게 나옴
시작 정점에서 탐색 + 시작 정점에서 가장 먼 정점(max_node)에서 탐색
dfs나 bfs를 두 번 돌려서 트리의 지점 찾기
max_node를 찾는 것!!
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> tree;
vector<bool> visited;

int max_dist = 0;
int max_node = 0;

void dfs(int node, int dist) {
	if (dist > max_dist) {
		max_node = node;
		max_dist = dist;
	}

	visited[node] = true;

	for (auto p : tree[node]) {
		int next_node = p.first, next_dist = p.second;
		if (!visited[next_node]) {
			dfs(next_node, dist + next_dist);
		}
	}
}

void bfs(int start) {
	queue<pair<int, int>> q;
	q.push({start, 0});
	visited[start] = true;

	while (!q.empty()) {
		int node = q.front().first, dist = q.front().second;
		q.pop();
		
		for (auto p : tree[node]) {
			int next_node = p.first, next_dist = p.second;
			
			if (!visited[next_node]) {
				q.push({ next_node, dist + next_dist });
				visited[next_node] = true;

				if (dist + next_dist > max_dist) {
					max_node = next_node;
					max_dist = dist + next_dist;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v; cin >> v;

	tree.resize(v + 1);
	visited = vector<bool>(v + 1, false);
	
	for (int i = 0; i < v; i++) {
		int n, e, d;
		cin >> n;
		while (cin >> e) {
			if (e == -1) break;
			cin >> d;
			tree[n].push_back({ e, d });
		}
	}
	
	dfs(1, 0);
	//bfs(1); 
	visited = vector<bool>(v + 1, false);
	dfs(max_node, 0);
	//bfs(max_node);

	cout << max_dist << '\n';
}
