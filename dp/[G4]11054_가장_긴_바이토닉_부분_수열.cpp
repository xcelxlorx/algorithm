//증가하는 부분 수열
//감소하는 부분 수열
//더하고 -1 
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;

	vector<int> v(n + 2), asc(n + 2, 0), desc(n + 2, 0);
	for (int i = 1; i <= n; i++) cin >> v[i];

	for (int i = 1; i <= n; i++) {
		int prev = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (v[j] < v[i]) {
				prev = max(prev, asc[j] + 1);
			}
		}
		asc[i] = prev;
	}

	for (int i = n; i > 0; i--) {
		int prev = 0;
		for (int j = i + 1; j <= n + 1; j++) {
			if (v[j] < v[i]) {
				prev = max(prev, desc[j] + 1);
			}
		}
		desc[i] = prev;
	}
	
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(answer, asc[i] + desc[i] - 1);
	}
	cout << answer;
}
