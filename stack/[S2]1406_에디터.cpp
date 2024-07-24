#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s; cin >> s;
	int m; cin >> m;

	stack<char> left, right;
	for (char c : s) left.push(c);
	while (m--) {
		char cmd; cin >> cmd;
		if (cmd == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (cmd == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (cmd == 'B') {
			if(!left.empty()) left.pop();
		}
		else if (cmd == 'P') {
			char c; cin >> c;
			left.push(c);
		}
	}

	string res = "";
	while (!left.empty()) {
		res += left.top();
		left.pop();
	}
	reverse(res.begin(), res.end());
	while (!right.empty()) {
		res += right.top();
		right.pop();
	}
	cout << res;
}
