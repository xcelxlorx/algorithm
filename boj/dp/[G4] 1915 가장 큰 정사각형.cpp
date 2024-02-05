#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			v[i][j] = s[j] - '0';
		}
	}

	int max_value = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i != 0 && j != 0 && v[i][j]) {
				int min_value = min({ v[i - 1][j] , v[i][j - 1] , v[i - 1][j - 1] });
				v[i][j] = min_value + 1;
			}
			max_value = max(max_value, v[i][j]);
		}
	}
	cout << max_value * max_value;
}
