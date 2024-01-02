#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	
	int start = 0, end = n - 1;
	int p1 = start, p2 = end;
	int value = 2000000000;
	while (start < end) {
		int cur = v[start] + v[end];

		if (abs(cur) <= value) {
			p1 = start;
			p2 = end;
			if (cur == 0) break;
			value = abs(cur);
		}

		if (cur < 0) start++;
		else end--;
	}

	cout << v[p1] << " " << v[p2];
}
