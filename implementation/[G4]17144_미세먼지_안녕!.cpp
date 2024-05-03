//미세먼지 확산 -> 공기청정기
//[i][j][0]: 자신의 미세먼지를 확산시킨 이후 값, [i][j][1]: 확산 받은 값 
#include <iostream>
#include <vector>

using namespace std;

int r, c;
int room[51][51][2] = { 0, };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int ax = -1;

void diffusion() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (room[i][j][0]) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
					if (room[nx][ny][0] == -1) continue;
					room[nx][ny][1] += room[i][j][0] / 5;
					cnt++;
				}
				room[i][j][0] -= room[i][j][0] / 5 * cnt;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			room[i][j][0] += room[i][j][1];
			room[i][j][1] = 0;
		}
	}
}

void clean() {
	//위-반시계
	for (int i = ax - 2; i >= 0; i--) room[i + 1][0][0] = room[i][0][0]; //하
	for (int j = 1; j < c; j++) room[0][j - 1][0] = room[0][j][0]; //좌
	for (int i = 1; i <= ax; i++) room[i - 1][c - 1][0] = room[i][c - 1][0]; //상
	for (int j = c - 2; j > 0; j--) room[ax][j + 1][0] = room[ax][j][0]; //우
	room[ax][1][0] = 0;

	//아래-시계
	for (int i = ax + 3; i < r; i++) room[i - 1][0][0] = room[i][0][0]; //상
	for (int j = 1; j < c; j++) room[r - 1][j - 1][0] = room[r - 1][j][0]; //좌
	for (int i = r - 2; i >= ax + 1; i--) room[i + 1][c - 1][0] = room[i][c - 1][0]; //하
	for (int j = c - 2; j > 0; j--) room[ax + 1][j + 1][0] = room[ax + 1][j][0]; //우
	room[ax + 1][1][0] = 0;
}

int main() {
	int t; cin >> r >> c >> t;
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> room[i][j][0];
			if (room[i][j][0] == -1 && ax == -1) ax = i;
		}
	}

	while (t--) {
		diffusion();
		clean();
	}

	int total = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if(room[i][j][0] > 0) total += room[i][j][0];
		}
	}
	cout << total;
}
