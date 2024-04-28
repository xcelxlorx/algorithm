//누적합 + 투포인터
#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int main() {
	int n, s; cin >> n >> s;

	vector<int> v(n + 1);
	for (int i = 0; i < n; i++) cin >> v[i];
	
	int answer = INF;
	int b = 0, e = 0, sum = v[0];
	while (b <= e) {
		if (b < 0 || e >= n) break;
		if (sum >= s) {
			answer = min(answer, e - b + 1);
			sum -= v[b++]; //길이 감소
		}else sum += v[++e]; //길이 증가
	}

	if (answer == INF) answer = 0;
	cout << answer;
}
