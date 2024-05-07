//스택
//depth: 몇 번째 괄호인지
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	string s; cin >> s;
	stack<char> st;
	vector<int> depth(31, 0);

	for (char c : s) {
		if (c == '(' || c == '[') st.push(c);
		else{
			if (st.empty() || (c == ')' && st.top() != '(') || (c == ']' && st.top() != '[')) {
				depth[0] = 0; 
				break;
			}

			st.pop();
			int d = st.size();
			int m = (c == ')') ? 2 : 3;

			if (depth[d + 1] == 0) depth[d] += m;
			else depth[d] += depth[d + 1] * m;
			depth[d + 1] = 0;
		}
	}

	if (st.size() > 0) depth[0] = 0;
	cout << depth[0];
}
