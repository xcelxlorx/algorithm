#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int main() {
	int n, lx = INF, ly = INF, rx = 0, ry = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char a; cin >> a;
			if (a == 'G') {
				lx = min(i, lx); ly = min(j, ly);
				rx = max(i, rx); ry = max(j, ry);
			}
		}
	}
	int x = min(rx, n - lx - 1), y = min(ry, n - ly - 1), dx = rx - lx, dy = ry - ly;
	if (!dx && !dy) cout << 0;
	else if (!dx && dy) cout << y;
	else if (dx && !dy) cout << x;
	else cout << x + y;
}
