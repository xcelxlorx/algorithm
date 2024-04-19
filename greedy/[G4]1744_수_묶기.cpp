//두 수 묶기
//양수끼리, 음수끼리, 큰 수끼리
//양수에서 1이 남을 경우 더하는 게 좋음
//음수가 남을 경우 0이랑 곱하는 게 좋음
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a; cin >> n;
	priority_queue<int> pos_pq;
	priority_queue<int, vector<int>, greater<int>> neg_pq;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > 0) pos_pq.push(a);
		else neg_pq.push(a);
	}

	int sum = 0;
	while (!pos_pq.empty()) {
		int cur = pos_pq.top();
		pos_pq.pop();

		if (!pos_pq.empty() && cur > 1 && pos_pq.top() > 1) {
			sum += cur * pos_pq.top();
			pos_pq.pop();
		}
		else sum += cur;
	}

	while (!neg_pq.empty()) {
		int cur = neg_pq.top();
		neg_pq.pop();

		if (!neg_pq.empty()) {
			sum += cur * neg_pq.top();
			neg_pq.pop();
		}
		else sum += cur;
	}
	cout << sum;
}
