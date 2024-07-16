#include <iostream>
using namespace std;

int main() {
	string s; cin >> s;

	int l = 0, siz = s.size(), answer = 1001;
	for (char c : s) if (c == 'a') l++;

	for (int j = 0; j < siz; j++) {
		int cnt = 0;
		for (int i = j; i < j + l; i++) if (s[i % siz] == 'b') cnt++;
		answer = min(answer, cnt);
	}
	cout << answer;
}
