//숫자가 변할 때를 기준으로 구분
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s; cin >> s;
	char c = s[0];
	int cnt = 1;
	for (int i = 1; i < s.size(); i++) {
		if (c != s[i]) {
			c = s[i]; cnt++;
		}
	}
	cout << cnt / 2 << endl;
}
