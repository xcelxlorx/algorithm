#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	int b, c; cin >> b >> c;

	long long answer = n;
	for (int i = 0; i < n; i++) {
		v[i] = max(v[i] - b, 0);
		answer += v[i] / c;
		answer += v[i] % c != 0 ? 1 : 0;
	}

	cout << answer;
}
