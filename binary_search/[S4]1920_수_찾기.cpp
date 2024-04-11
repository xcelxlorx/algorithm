#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

bool binary_search(int target) {
	int start = 0, end = v.size() - 1;

	while (start <= end) {
		int mid = (start + end) / 2;

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

	int n, a; cin >> n;
	while (n--) {
		cin >> a; 
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int m; cin >> m;
	while (m--) {
		cin >> a;
		cout << binary_search(a) << '\n';
	}
}
