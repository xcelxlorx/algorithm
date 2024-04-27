#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<vector<int>> box;
int cnt = 0, t = 0;
int gx, gy, gd = INF;
int baby_size = 2;

void move() {
	queue<vector<int>> q;
	vector<vector<int>> visited(n, vector<int>(n, 0));
	q.push({gx, gy, 0}); //x y d
	visited[gx][gy] = 1; 

	while (!q.empty()) {
		auto v = q.front();
		int x = v[0], y = v[1], d = v[2];
		q.pop();

		//위치 찾기
		if (box[x][y] < baby_size && box[x][y] > 0) {
			if (gd > d) {
				gx = x; gy = y; gd = d;
			}
			else if (gd == d) {
				if (gx > x) {
					gx = x; gy = y; gd = d;
				}
				else if (gx == x) {
					if (gy > y) {
						gx = x; gy = y; gd = d;
					}
				}
			}
			continue;
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			if (!visited[nx][ny] && box[nx][ny] <= baby_size) {
				q.push({ nx, ny, d + 1 });
				visited[nx][ny] = 1;
			}
		}
	}
	
	//이동해서 물고기를 먹음
	if (gd != INF) {
		t += gd;
		cnt++;
		box[gx][gy] = 0;
	}

	//같은 수의 물고기를 먹을 때마다 아기 상어의 크기는 증가
	if (cnt == baby_size) {
		baby_size++;
		cnt = 0;
	}
}

int main() {
	cin >> n;

	box = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> box[i][j];
			if (box[i][j] == 9) {
				gx = i; gy = j;
				box[i][j] = 0;
			}
		}
	}

	while (1) {
		move();
		if (gd == INF) break;
		gd = INF;
	}
	cout << t;
}
