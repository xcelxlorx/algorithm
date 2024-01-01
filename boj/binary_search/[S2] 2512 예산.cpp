#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int binary_search(long long total) {
	int start = 1, end = v[v.size() - 1];
	while (start <= end) {
		int mid = (start + end) / 2;

		long long sum = 0;
		for (auto e : v) sum += min(e, mid);

		if (sum > total) end = mid - 1;
		else start = mid + 1;
	}
	return end;
}

int main() {
	int n; cin >> n;

	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	long long total; cin >> total;

	cout << binary_search(total);
}
