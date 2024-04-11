#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int m, n; cin >> m;

		priority_queue<int> pq_desc;
		priority_queue<int, vector<int>, greater<int>> pq_asc;
		vector<int> answer;

		for (int i = 1; i <= m; i++) {
			cin >> n;
			if (pq_desc.empty() || pq_desc.top() >= n) pq_desc.push(n);
			else pq_asc.push(n);

			if (pq_desc.size() < pq_asc.size()) {
				pq_desc.push(pq_asc.top());
				pq_asc.pop();
			}
			else if (pq_desc.size() - 1 > pq_asc.size()) {
				pq_asc.push(pq_desc.top());
				pq_desc.pop();
			}

			if (i % 2) answer.push_back(pq_desc.top());
		}

		cout << answer.size() << '\n';
		for (int i = 0; i < answer.size(); i++) {
			if (i % 10 == 0 && i != 0) cout << '\n';
			cout << answer[i] << " ";
		}
		cout << '\n';
	}
}
