#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	vector<vector<bool>> visited(n, vector<bool>(m, 0));
	set<vector<pair<int, int>>> answer;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] && !visited[i][j]) {
				if (k == 1) {
					visited[i][j] = 1;
					answer.insert({ {i, j} });
				}
				else {
					for (int d = 0; d < 4; d++) {
						if (visited[i][j]) break;
						int x = i, y = j, cnt = 1;
						vector<pair<int, int>> row;
						row.push_back({ x, y });
						while (1) {
							int nx = x + dx[d], ny = y + dy[d];
							if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
							if (cnt == k || !v[nx][ny]) break;
							cnt++;
							x = nx; y = ny;
							row.push_back({ x, y });
						}
						if (cnt == k) {
							for (auto p : row) visited[p.first][p.second] = 1;
							answer.insert(row);
						}
					}
				}
			}
		}
	}

	auto it = answer.begin();
	vector<pair<int, int>> v1 = *it;
	if (answer.size() == 1) {
		cout << v1.size() << '\n';
		for (auto p : v1) cout << p.first + 1 << " " << p.second + 1 << '\n';
	}
	else {
		vector<pair<int, int>> v2, inter(k * 2 + 1);
		v2 = *(++it);

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		auto iter = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inter.begin());
		inter.erase(iter, inter.end());

		cout << inter.size() << '\n';
		for (auto p : inter) cout << p.first + 1 << " " << p.second + 1 << '\n';
	}
}
