//원의 중심 사이의 거리와 반지름 비교
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t; cin >> t;
	int x, y;
	while (t--) {
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		d = sqrt(d);

		if (d == 0) {
			if (r1 - r2 != 0) cout << 0 << '\n';
			else cout << -1 << '\n';
		}
		else if (d == r1 + r2 || d == abs(r1 - r2)) cout << 1 << '\n';
		else if (d > abs(r1 - r2) && d < r1 + r2) cout << 2 << '\n';
		else cout << 0 << '\n';
	}
}
