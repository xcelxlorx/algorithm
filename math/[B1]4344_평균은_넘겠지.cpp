#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, n; cin >> t;

	cout << fixed;
	cout.precision(3);

	while (t--) {
		cin >> n;

		vector<int> v(n);
		double avg = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			avg += v[i];
		}
		avg /= n;

		double cnt = 0;
		for (int e : v) if (e > avg) cnt++;
		
		cout << cnt / n * 100 << "%" << '\n';
	}
}
