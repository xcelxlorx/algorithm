//dp + 슬라이딩 윈도우
//bfs - 메모리 초과 dfs - 시간 초과
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int row[2][3][2] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> row[1][j][0];
			row[1][j][1] = row[1][j][0];
		}
		for (int j = 0; j < 3; j++) {
			int l = j == 0 ? 0 : j - 1;
			int r = j == 2 ? 2 : j + 1;

			int cur_min = 987654321, cur_max = -1;
			for (int k = l; k <= r; k++) {
				cur_max = max(cur_max, row[0][k][0]);
				cur_min = min(cur_min, row[0][k][1]);
			}

			row[1][j][0] += cur_max;
			row[1][j][1] += cur_min;
		}
		for (int j = 0; j < 3; j++) {
			row[0][j][0] = row[1][j][0];
			row[0][j][1] = row[1][j][1];
		}
	}
		
	cout << max({ row[1][0][0] , row[1][1][0] , row[1][2][0] }) << " ";
	cout << min({ row[1][0][1] , row[1][1][1] , row[1][2][1] });
}
