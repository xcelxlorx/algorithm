#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

vector<vector<int>> graph;
int n;

void floyd_warshall() {
	//경유지 k, 출발 노드 i, 도착 노드 j
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

int main() {
	int m, a, b, c; cin >> n >> m;

	graph = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a][b] = min(c, graph[a][b]);
	}

	floyd_warshall();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == INF) cout << 0 << " ";
			else cout << graph[i][j] << " ";
		}
		cout << '\n';
	}
}
