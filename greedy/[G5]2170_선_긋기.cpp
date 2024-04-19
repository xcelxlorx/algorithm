//sweeping
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, y; cin >> n;
	vector<vector<int>> v(n); //x y
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v[i] = { x, y };
	}

	sort(v.begin(), v.end());

	int start = v[0][0], end = v[0][1], l = 0;
	for (auto p : v) {
		if (p[0] > end) {
			//띄워진 선
			l += end - start;
			start = p[0]; 
			end = p[1];
		}else {
			//겹쳐진 선
			end = max(end, p[1]);
		}
	}
	cout << l + end - start;
}
