#include <iostream>
#define SMAX 200001
#define NMAX 100001
using namespace std;

int seq[SMAX];
int num[NMAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> seq[i];

	int b = 0, e = 0, max_seq = 0;
	while (b <= e && e < n) {
		if (num[seq[e]] + 1 > k) num[seq[b++]]--;
		else {
			max_seq = max(max_seq, e - b + 1);
			num[seq[e++]]++;
		}
	}
	cout << max_seq;
}
