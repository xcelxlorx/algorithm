#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, d, p; cin >> n;

	vector<vector<int>> v(10001);
	while (n--) {
		cin >> p >> d;
		v[d].push_back(p);
	}

	int sum = 0;
	priority_queue<int> pq;
	for (int i = 10000; i >= 1; i--) {
		for (int e : v[i]) pq.push(e);
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;
}
