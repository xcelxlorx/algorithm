//유니온 파인드
//모든 파티 인원이 진실을 모르는 사람들로 구성되어야 함
//파티 전체를 고려해야 함
//부모를 찾아야 함
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph;

int find_node(int node) {
	if (graph[node] == node) return node;
	graph[node] = find_node(graph[node]);
	return graph[node];
}

void merge(int a, int b) {
	int ranode = find_node(a);
	int rbnode = find_node(b);
	if (ranode != rbnode) graph[ranode] = rbnode;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;

	graph.resize(n + 1);
	for (int i = 1; i <= n; i++) graph[i] = i; 

	int tn; cin >> tn;
	vector<int> truth(tn);
	for (int i = 0; i < tn; i++) cin >> truth[i]; //진실을 아는 사람 저장

	vector<vector<int>> group(m);
	int pn;
	for (int i = 0; i < m; i++) {
		cin >> pn; 
		group[i].resize(pn);
		cin >> group[i][0];
		for (int j = 1; j < pn; j++) {
			cin >> group[i][j];
			merge(graph[group[i][j]], graph[group[i][0]]); //같은 파티는 그룹
		}
	}

	for (int i = 1; i <= n; i++) 
		find_node(i); //대표 노드를 구함

	for (int i = 0; i < tn; i++) 
		truth[i] = graph[truth[i]]; //진실을 아는 사람을 대표 노드로 업데이트

	int cnt = 0;
	for (auto people : group) {
		int cur = graph[people[0]];
		auto it = find(truth.begin(), truth.end(), cur);
		if (it == truth.end()) cnt++;
	}
	cout << cnt;
}
