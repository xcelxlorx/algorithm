#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<pair<int, int>>> board;
vector<char> turn;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int move() {
	int hx = 1, hy = 1, tx = 1, ty = 1;
	int cnt = 0;
	board[hx][hy] = { 2, 0 };

	while (1) {
		auto p = board[hx][hy];
		int d = p.second;
		int nx = hx + dx[d], ny = hy + dy[d];

		if (nx <= 0 || nx > n || ny <= 0 || ny > n) break;
		if (board[nx][ny].first == 2) break;

		if (board[nx][ny].first == 1) {
			//사과가 있으면 꼬리를 움직이지 않음 + 머리 움직임
			hx = nx; hy = ny;
			board[hx][hy] = { 2, d };
		}else {
			//사과가 없으면 꼬리를 움직임 + 머리 움직임
			int td = board[tx][ty].second;
			int tnx = tx + dx[td], tny = ty + dy[td];
			board[tx][ty] = { 0, 0 };
			tx = tnx; ty = tny;

			hx = nx; hy = ny;
			board[hx][hy] = { 2, d };
		}

		cnt++;
		if (turn[cnt] != ' ') {
			int d = board[hx][hy].second;
			if (turn[cnt] == 'L') d = d - 1 < 0 ? 3 : d - 1;
			else d = d + 1 > 3 ? 0 : d + 1;
			board[hx][hy].second = d;
		}
	}
	return cnt + 1;
}

int main() {
	int k, r, c; cin >> n >> k;
	board = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>(n + 1));
	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		board[r][c] = { 1, 0 }; //사과, 방향
	}
	int l, x; char ch; cin >> l;
	turn = vector<char>(10001, ' ');
	for (int i = 0; i < l; i++) {
		cin >> x >> ch;
		turn[x] = ch;
	}
	cout << move();
}
