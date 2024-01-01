//algorithm 헤더에 있는 binary_search를 이용할 수 있음

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> v;

bool binary_search(int target) {
	long long start = 0, end = v.size() - 1;

	while (start <= end) {
		long long mid = (start + end) / 2;

		if (v[mid] < target) start = mid + 1;
		else if (v[mid] > target) end = mid - 1;
		else return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	v.resize(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	int m; cin >> m;
	long long target;
	while (m--) {
		cin >> target;
		//cout << binary_search(v.begin(), v.end(), target) << ' ';
		cout << binary_search(target) << ' ';
	}
}
