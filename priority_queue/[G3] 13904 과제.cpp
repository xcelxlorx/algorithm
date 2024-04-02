#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, d, w; cin >> n;

	vector<vector<int>> v(1001);
	while (n--) {
		cin >> d >> w;
		v[d].push_back(w);
	}

	int sum = 0;
	priority_queue<int> pq;
	for (int i = 1000; i >= 1; i--) {
		for (int e : v[i]) pq.push(e);
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;
}
