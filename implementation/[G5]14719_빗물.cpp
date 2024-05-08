#include <iostream>
#include <vector>

using namespace std;

int main() {
	int h, w; cin >> h >> w;

	vector<int> v(w), l(w), r(w);
	for (int i = 0; i < w; i++) cin >> v[i];

	l = v;
	for (int i = 1; i < w; i++) {
		if (l[i - 1] > l[i]) l[i] = l[i - 1];
	}

	r = v;
	for (int i = w - 1; i > 0; i--) {
		if (r[i - 1] < r[i]) r[i - 1] = r[i];
	}

	int answer = 0;
	for (int i = 0; i < w; i++) {
		answer += min(l[i], r[i]) - v[i];
	}
	cout << answer;
}
