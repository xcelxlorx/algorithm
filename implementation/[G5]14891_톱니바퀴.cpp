//각 톱니바퀴를 회전 여부에 따라 회전시킴
//왼쪽이랑 비교: s[2], 오른쪽이랑 비교: s[6]
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;


string rotation(string s, int d) {
	if (d == 1) return s[7] + s.substr(0, 7); //시계 방향
	else return s.substr(1) + s[0]; //반시계 방향
}

int main() {
	vector<string> gear(5);
	for (int i = 1; i <= 4; i++) cin >> gear[i];

	int k, n, d; cin >> k; //회전 횟수
	for (int i = 0; i < k; i++) {
		cin >> n >> d; //회전시킨 톱니바퀴 번호, 방향

		bool same12 = gear[1][2] == gear[2][6];
		bool same23 = gear[2][2] == gear[3][6];
		bool same34 = gear[3][2] == gear[4][6];

		if (n == 1) {
			//1-2-3-4
			gear[1] = rotation(gear[1], d); //1번 회전
			
			if (!same12) gear[2] = rotation(gear[2], -d); //2번 회전
			else continue; //2번이 회전하지 않을 경우 3번은 회전할 수 없음
			
			if (!same23) gear[3] = rotation(gear[3], d); //3번 회전
			else continue;
			
			if (!same34) gear[4] = rotation(gear[4], -d); //4번 회전
		}
		else if (n == 2) {
			//2-1/3-4
			gear[2] = rotation(gear[2], d); //2번 회전
			
			if (!same12) gear[1] = rotation(gear[1], -d); //1번 회전
			
			if (!same23) gear[3] = rotation(gear[3], -d); //3번 회전
			else continue;
			
			if (!same34) gear[4] = rotation(gear[4], d); //4번 회전
		}
		else if (n == 3) {
			//3-2/4-1
			gear[3] = rotation(gear[3], d); //3번 회전
			
			if (!same34) gear[4] = rotation(gear[4], -d); //4번 회전
			
			if (!same23) gear[2] = rotation(gear[2], -d); //2번 회전
			else continue;
			
			if (!same12) gear[1] = rotation(gear[1], d); //1번 회전
		}
		else if (n == 4) {
			//4-3-2-1
			gear[4] = rotation(gear[4], d); //4번 회전
			
			if (!same34) gear[3] = rotation(gear[3], -d); //3번 회전
			else continue;
			
			if (!same23) gear[2] = rotation(gear[2], d); //2번 회전
			else continue;
			
			if (!same12) gear[1] = rotation(gear[1], -d); //1번 회전
		}
	}

	int score = 0;
	if (gear[1][0] == '1') score += 1;
	if (gear[2][0] == '1') score += 2;
	if (gear[3][0] == '1') score += 4;
	if (gear[4][0] == '1') score += 8;
	cout << score;
}
