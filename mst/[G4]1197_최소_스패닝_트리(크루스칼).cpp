#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> edge;
vector<int> parent;
int v, e;

int find(int cur) {
	//부모 노드를 찾음
	if (cur == parent[cur]) return cur; //대표 노드일 경우
	return find(parent[cur]);
}

void merge(int n1, int n2) {
	//두 노드 연결하기(부모 노드 일치시키기)
	n1 = find(n1);
	n2 = find(n2);
	parent[n2] = n1;
}

long long kruskal() {
	//1. 가중치에 따라 오름차순 정렬
	sort(edge.begin(), edge.end());

	//2. 현재의 간선이 사이클을 발생시키는지 확인
	long long sum = 0;
	for (auto cur : edge) {
		//같은 부모가 아니라면, 연결해도 사이클이 생기지 않음
		if (find(cur[1]) != find(cur[2])) {
			merge(cur[1], cur[2]);
			sum += cur[0];
		}
	}
	return sum;
}

int main() {
	int a, b, c; cin >> v >> e;

	//유니온 파인드 부모 노드 초기화
	parent = vector<int>(v + 1, 0);
	for (int i = 1; i <= v; i++) parent[i] = i;

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		edge.push_back({ c, a, b }); //가중치, 노드1, 노드2
	}

	cout << kruskal();
}
