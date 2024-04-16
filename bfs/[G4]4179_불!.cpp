//최단 거리 -> bfs
//J 이동 -> 불 이동
//불이 지나간 시간을 기록
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<vector<char>> v;
vector<vector<int>> f;
int answer = INF;
int r, c; 

void fire() {
	queue<vector<int>> q;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!f[i][j]) q.push({ i, j, 0 });
		}
	}

	while (!q.empty()) {
		auto e = q.front();
		q.pop();
		
		for (int k = 0; k < 4; k++) {
			int nx = e[0] + dx[k], ny = e[1] + dy[k];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (f[nx][ny] == INF && v[nx][ny] != '#') {
				f[nx][ny] = e[2] + 1;
				q.push({ nx, ny, e[2] + 1 });
			}
		}
	}
}

void bfs(int x, int y) {
	queue<vector<int>> q; //x, y, time
	v[x][y] = '0'; 
	q.push({ x, y, 0 });

	while (!q.empty()) {
		auto top = q.front();
		x = top[0]; y = top[1]; 
		q.pop();
		
		if (f[x][y] <= top[2]) continue; //불에 탄 시간 <= 도착한 시간

		if (x == 0 || y == 0 || x == r - 1 || y == c - 1) {
			answer = min(answer, top[2] + 1);
			break;
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (v[nx][ny] == '.') {
				v[nx][ny] = '0';
				q.push({ nx, ny, top[2] + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x = 0, y = 0; cin >> r >> c;
	v = vector<vector<char>>(r, vector<char>(c, ' '));
	f = vector<vector<int>>(r, vector<int>(c, INF));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'J') {
				x = i; y = j;
			}
			if (v[i][j] == 'F') f[i][j] = 0;
		}
	}

	fire();
	bfs(x, y);

	if (answer == INF) cout << "IMPOSSIBLE";
	else cout << answer;
}
