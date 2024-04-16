//제곱수는 계단식
//1 -> 1, 4 -> 121, 9 -> 12321, 16 -> 1234321
//dist보다 작고 제곱수 중에서 가장 큰 수를 찾음
//나머지는 규칙을 찾아서 계산

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	long long start, end;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;

		long long d = end - start, s = 1;
		while (s * s < d) s++; //최대 제곱수
		
		if (d == s * s) cout << s * 2 - 1 << '\n';
		else {
			s--;
			cout << s * 2 - 1 + (d - s * s - 1) / s + 1 << '\n';
		}
	}
}
