#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> belt(n * 2);
	for (int i = 0; i < n * 2; i++) cin >> belt[i];

	vector<bool> robot(n * 2);
	int b = 0, e = n - 1, step = 1;
	while (1) {
		//1. 벨트 회전
		b = (b == 0) ? n * 2 - 1 : b - 1;
		e = (e == 0) ? n * 2 - 1 : e - 1;
		if (robot[e]) robot[e] = 0;

		//2. 로봇 이동
		int cur = e == 0 ? n * 2 - 1 : e - 1;
		for (int i = 0; i < n - 1; i++) {
			int next = (cur + 1) % (n * 2);
			if (robot[cur] && !robot[next] && belt[next]) {
				robot[next] = 1;
				robot[cur] = 0;
				belt[next]--;
			}
			cur = cur == 0 ? n * 2 - 1 : cur - 1;
		}
		if (robot[e]) robot[e] = 0;

		//3. 짐 올리기
		if (belt[b]) {
			robot[b] = 1;
			belt[b]--;
		}

		//4. 내구도 확인
		int cnt = 0;
		for (int e : belt) if (!e) cnt++;
		if (cnt >= k) break;
		step++;
	}
	cout << step;
}
