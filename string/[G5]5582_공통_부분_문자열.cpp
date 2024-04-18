#include <iostream>
#include <vector>

using namespace std;

int main() {
	string a, b; cin >> a >> b;
	int n = a.size(), m = b.size();
	vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j]) {
				v[i + 1][j + 1] = v[i][j] + 1;
				answer = max(answer, v[i + 1][j + 1]);
			}
		}
	}
	cout << answer;
}
