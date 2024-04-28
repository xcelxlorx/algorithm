//동전의 최소 개수
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int main() {
	int n, k; cin >> n >> k;

	vector<int> v(n), cnt(k + 1, INF);
	for (int i = 0; i < n; i++) cin >> v[i];

	cnt[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if(j - v[i] >= 0) cnt[j] = min(cnt[j - v[i]] + 1, cnt[j]);
		}
	}

	if (cnt[k] == INF) cnt[k] = -1;
	cout << cnt[k];
}
