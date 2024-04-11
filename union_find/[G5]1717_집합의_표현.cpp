//유니온 파인드
//배열에는 대표 노드가 저장됨
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

//대표 노드 찾기
int find_node(int node) {
	if (v[node] == node) return node;
	v[node] = find_node(v[node]);
	return v[node];
}

//두 집합을 합침
//b에 a의 대표 노드를 저장
void merge(int a, int b) {
	int ranode = find_node(a);
	int rbnode = find_node(b);
	if (ranode != rbnode) v[rbnode] = ranode;
}

//두 집합의 대표 노드를 찾아서 동일한지 비교
void find(int a, int b) {
	int ranode = find_node(a);
	int rbnode = find_node(b);
	if (ranode == rbnode) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	
	v.resize(n + 1);
	for (int i = 0; i <= n; i++) v[i] = i;

	int op, a, b;
	while (m--) {
		cin >> op >> a >> b;
		op ? find(a, b) : merge(a, b);
	}
}
