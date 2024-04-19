#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int cnt = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (v[i + 1] <= v[i]) {
			int diff = v[i] - v[i + 1] + 1;
			cnt += diff;
			v[i] -= diff;
		}
	}
	cout << cnt;
}
