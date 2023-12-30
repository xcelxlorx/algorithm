//이미 방문한 알파벳을 체크하기 때문에 visited 배열을 만들 필요 없음
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int r, c;
map<char, bool> m;
vector<vector<char>> board;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int max_depth = 0;

void dfs(int x, int y, int depth) {

	max_depth = max_depth < depth ? depth : max_depth;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];

		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		
		if (!m[board[nx][ny]]) {
			m[board[nx][ny]] = 1;
			dfs(nx, ny, depth + 1);
			m[board[nx][ny]] = 0;
		}
	}
}

int main() {
	cin >> r >> c;

	board = vector<vector<char>>(r, vector<char>(c));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char ch; cin >> ch;
			board[i][j] = ch;
		}
	}

	m[board[0][0]] = 1;
	dfs(0, 0, 1);
	cout << max_depth << '\n';
}
