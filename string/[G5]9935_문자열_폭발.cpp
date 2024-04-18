//replace는 시간초과
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	string s, bomb; cin >> s >> bomb;
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		st.push(s[i]);
		if (bomb[bomb.size() - 1] == st.top() && st.size() >= bomb.size()) {
			string temp = "";
			int idx = 0;
			while (idx++ < bomb.size()) {
				temp += st.top();
				st.pop();
			}
			reverse(temp.begin(), temp.end());
			if (temp != bomb) for (int e : temp) st.push(e);
		}
	}

	string answer = "";
	while (!st.empty()) {
		answer += st.top();
		st.pop();
	}
	reverse(answer.begin(), answer.end());

	if (answer.size() == 0) cout << "FRULA";
	else cout << answer;
}
