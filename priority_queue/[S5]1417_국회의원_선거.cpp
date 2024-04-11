#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, result, a; cin >> n >> result; 
	priority_queue<int> pq;
	for (int i = 0; i < n - 1; i++) {
		cin >> a;  pq.push(a);
	}

	int cnt = 0;
	while (!pq.empty()) {
		if (pq.top() < result) break;
		int temp = pq.top();
		pq.pop();
		pq.push(temp - 1);
		cnt++; result++;
	}
	cout << cnt;
}
