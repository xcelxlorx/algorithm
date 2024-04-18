#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		bool palin = 0;
		int l = 0, r = s.size() - 1, jump = 0;
		queue<vector<int>> q; 
		q.push({ l, r, jump });

		while (!q.empty()) {
			auto v = q.front();
			l = v[0], r = v[1], jump = v[2];
			q.pop();
			
			if (l >= r) {
				palin = 1;
				break;
			}

			if (s[l] == s[r]) q.push({ l + 1, r - 1, jump });
			else {
				int state = 0;
				if (!jump && s[l + 1] == s[r]) {
					q.push({ l + 1, r, 1 });
					state = 1;
				}
				if (!jump && s[l] == s[r - 1]) {
					q.push({ l, r - 1, 1 });
					state = 2;
				}
			}
		}

		if (!jump && palin) cout << 0 << '\n';
		else if (jump && palin) cout << 1 << '\n';
		else cout << 2 << '\n';
	}
}
