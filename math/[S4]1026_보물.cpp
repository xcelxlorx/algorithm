#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	int m = 0;
	for (int i = 0; i < n; i++) m += a[i] * b[i];
	cout << m;
}
