//애드 혹
//w랑 h는 +- 반복 
//t % (2 * w), t % (2 * h)
#include <iostream>

using namespace std;

int main() {
	int w, h, p, q, t; cin >> w >> h >> p >> q >> t;

	int wt = t % (2 * w), ht = t % (2 * h);
	p = (p + wt >= w) ? 2 * w - (p + wt) : p + wt;
	p = p < 0 ? -p : p;
	q = (q + ht >= h) ? 2 * h - (q + ht) : q + ht;
	q = q < 0 ? -q : q;

	cout << p << " " << q;
}
