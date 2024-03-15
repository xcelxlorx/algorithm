#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<int>> s(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	vector<int> idx(n, 1);
	for (int i = 0; i < n / 2; i++) idx[i] = 0;

	int diff = 987654321;
	do {
		int start = 0, link = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((idx[i] ^ idx[j]) == 0) {
					if (idx[i] == 0) start = start + s[i][j];
					else link = link + s[i][j];
				}
			}
		}
		diff = min(diff, abs(start - link));
	} while (next_permutation(idx.begin(), idx.end()));
	cout << diff;
}
