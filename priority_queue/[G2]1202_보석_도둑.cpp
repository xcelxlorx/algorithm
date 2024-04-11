#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k, m, v, c; cin >> n >> k;

	vector<vector<int>> je; //무게, 가격
	while (n--) {
		cin >> m >> v;
		je.push_back({ m, v });
	}

	vector<int> bag;
	while (k--) {
		cin >> c;
		bag.push_back(c);
	}

	sort(je.begin(), je.end());
	sort(bag.begin(), bag.end());

	priority_queue<int> pq;
	int ji = 0;
	long long sum = 0;
	for (int w : bag) {
		while (1) {
			if (ji >= je.size()) break;
			if (je[ji][0] > w) break;
			pq.push(je[ji++][1]);
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;
}
