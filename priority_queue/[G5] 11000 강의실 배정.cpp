//시작 시간이 pq.top 보다 작을 경우 강의실 사용이 겹침
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s, e; cin >> n;

	vector<vector<int>> v(n);
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		v[i] = { s, e };
		pq.push(-e);
	}

	sort(v.begin(), v.end());

	for (int i = 1; i < v.size(); i++) {
		if (v[i][0] >= -pq.top()) pq.pop(); //겹치지 않음
	}
	cout << pq.size();
}
