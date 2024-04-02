//O(N)에서 중간값 구하기
//최소 pq, 최대 pq에서 최소 pq의 top을 중간값으로 설정

#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, d; cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq_asc;
	priority_queue<int> pq_desc;

	while (n--) {
		cin >> d;

		if(pq_desc.empty() || pq_desc.top() >= d) pq_desc.push(d);
		else pq_asc.push(d);
		
		if (pq_desc.size() < pq_asc.size()) {
			int top = pq_asc.top();
			pq_asc.pop();
			pq_desc.push(top);
		}
		else if (pq_desc.size() - 1 > pq_asc.size()) {
			int top = pq_desc.top();
			pq_desc.pop();
			pq_asc.push(top);
		}

		cout << pq_desc.top() << '\n';
	}
}
