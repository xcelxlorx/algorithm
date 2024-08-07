#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string w; int t, k;
	cin >> t;
	while (t--) {
		cin >> w >> k;
		vector<vector<int>> v(26);
		for (int i = 0; i < w.size(); i++) {
			v[w[i] - 97].push_back(i);
		}

		int maxl = 0, minl = INF;
		for (int i = 0; i < 26; i++) {
			if (v[i].size() < k) continue;
			int max_cur = 0, min_cur = INF;
			for (int j = k - 1; j < v[i].size(); j++) {
				max_cur = max(max_cur, v[i][j] - v[i][j - k + 1] + 1);
				min_cur = min(min_cur, v[i][j] - v[i][j - k + 1] + 1);
			}
			maxl = max(max_cur, maxl);
			minl = min(min_cur, minl);
		}
		if (maxl == 0) cout << -1 << '\n';
		else cout << minl << " " << maxl << '\n';
	}
}
