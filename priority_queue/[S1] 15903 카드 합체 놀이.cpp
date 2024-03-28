#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, m, a; cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < n; i++) {
		cin >> a; pq.push(a);
	}

	while (m--) {
		long long n1 = pq.top(); pq.pop();
		long long n2 = pq.top(); pq.pop();
		pq.push(n1 + n2);
		pq.push(n1 + n2);
	}

	long long sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
}
