//s -> t
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string s, t; cin >> s >> t;
	bool change = 0;
	for (int i = t.size() - 1; i >= 0; i--) {
		if (i + 1 == s.size()) {
			string temp = t.substr(0, i + 1);
			if (temp == s) {
				change = 1; break;
			}
		}
		string temp = t.substr(0, i);
		if (t[i] == 'B') reverse(temp.begin(), temp.end());
		t = temp;
	}
	cout << change;
}
