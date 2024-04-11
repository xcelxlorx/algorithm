//N을 1개 제거 -> 왼쪽 최대 연속 합의 L[N-1] + 오른쪽 최대 연속 합의 R[N+1]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];

	vector<int> dpl(n + 1, 0), dpr(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		dpl[i] = max(dpl[i - 1] + v[i], v[i]);
		dpr[n + 1 - i] = max(dpr[n - i + 2] + v[n + 1 - i], v[n + 1 - i]);
	}

	int answer = max(*max_element(dpl.begin() + 1, dpl.end()), *max_element(dpr.begin() + 1, dpr.end() - 1));

	if (n != 1) {
		for (int i = 1; i <= n; i++) {
			if (answer < dpl[i - 1] + dpr[i + 1])
				answer = dpl[i - 1] + dpr[i + 1];
		}
	}

	cout << answer << '\n';
}
