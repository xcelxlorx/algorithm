#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int r, c; cin >> r >> c;
		vector<vector<char>> board(r, vector<char>(c));
		bool heart = 1;

		//외부 사각형(크림)을 구함
		int lx = r, ly = c, rx = -1, ry = -1;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> board[i][j];
				if (board[i][j] == '#') {
					lx = min(i, lx); ly = min(j, ly);
					rx = max(i, rx); ry = max(j, ry);
				}
			}
		}

		//외부 사각형이 정사각형인지 확인
		if (rx < 0 || rx - lx != ry - ly) heart = 0;

		//이어진 내부 사각형(blank)을 구함
		int ilx = r, ily = c, irx = -1, iry = -1;
		if (heart) {
			for (int i = lx; i <= rx; i++) {
				for (int j = ly; j <= ry; j++) {
					if (board[i][j] == '.') {
						ilx = min(i, ilx); ily = min(j, ily);
						irx = max(i, irx); iry = max(j, iry);
					}
				}
			}
		}

		//내부 사각형이 정사각형인지 확인
		if (irx < 0 || irx - ilx != iry - ily) heart = 0;

		//내부 사각형 안은 채워져 있으면 안됨
		if (heart) {
			for (int i = ilx; i <= irx; i++) {
				for (int j = ily; j <= iry; j++) {
					if (board[i][j] == '#') {
						heart = 0;
						break;
					}
				}
				if (!heart) break;
			}
		}

		//내부 사각형을 제외한 외부 사각형은 채워져 있어야 함
		if (heart) {
			for (int i = lx; i <= rx; i++) {
				for (int j = ly; j <= ry; j++) {
					if (i >= ilx && i <= irx && j >= ily && j <= iry) continue;
					if (board[i][j] == '.') {
						heart = 0;
						break;
					}
				}
				if (!heart) break;
			}
		}

		//내부 사각형과 외부 사각형의 꼭짓점이 겹쳐야 함
		if (heart && !((board[lx][ly] == board[ilx][ily]) || board[lx][ry] == board[ilx][iry]
			|| board[rx][ly] == board[irx][ily] || board[rx][ry] == board[irx][iry])) {
			heart = 0;
		}

		cout << heart << '\n';
	}
}
