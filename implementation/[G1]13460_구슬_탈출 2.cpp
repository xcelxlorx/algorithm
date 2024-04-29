//탐색
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<char>> board;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void move(int k, int& x, int& y) {
	while (1) {
		if (board[x + dx[k]][y + dy[k]] == '#') break;
		if (board[x][y] == 'O') break;
		x += dx[k]; y += dy[k];
	}
}

int bfs(int rx, int ry, int bx, int by) {
	queue<vector<int>> q;
	q.push({ rx, ry, bx, by, 0 }); //rx, ry, bx, by, cnt
	bool visited[11][11][11][11] = { 0, }; 
	visited[rx][ry][bx][by] = 1;

	while (!q.empty()) {
		auto v = q.front();
		rx = v[0], ry = v[1], bx = v[2], by = v[3]; 
		int cnt = v[4];
		q.pop();
		
		if (cnt > 10) return -1;
		if (board[rx][ry] == 'O') return cnt;

		for (int k = 0; k < 4; k++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;

			move(k, nrx, nry); //빨간 구슬 이동
			move(k, nbx, nby); //파란 구슬 이동

			if (board[nbx][nby] == 'O') continue; //파란 구슬이 구멍에 들어감

			//구슬의 위치가 동일할 경우, 많이 이동한 구슬이 뒤에 있는 구슬
			if (nrx == nbx && nry == nby) {
				int rd = abs(nrx - rx) + abs(nry - ry);
				int bd = abs(nbx - bx) + abs(nby - by);

				if (rd < bd) nbx -= dx[k], nby -= dy[k]; //파란 구슬을 한 칸 뒤로
				else nrx -= dx[k], nry -= dy[k];
			}

			if (!visited[nrx][nry][nbx][nby]) {
				q.push({ nrx, nry, nbx, nby, cnt + 1 });
				visited[nrx][nry][nbx][nby] = 1;
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	string s;

	board = vector<vector<char>>(n, vector<char>(m));
	int rx = 0, ry = 0, bx = 0, by = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j];
			if (board[i][j] == 'R') {
				rx = i; ry = j;
			}
			if (board[i][j] == 'B') {
				bx = i; by = j;
			}
		}
	}

	cout << bfs(rx, ry, bx, by);
}
