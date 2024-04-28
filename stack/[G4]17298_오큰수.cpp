#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int n; cin >> n;

	vector<int> v(n), answer(n, 0);
	stack<int> st;
	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = n - 1; i >= 0; i--) {
		if (st.empty()) answer[i] = -1;
		else {
			if (st.top() > v[i]) answer[i] = st.top();
			else {
				while (!st.empty()) {
					if (st.top() <= v[i]) st.pop();
					else break;
				}
				if (st.empty()) answer[i] = -1;
				else answer[i] = st.top();
			}
		}
		st.push(v[i]);
	}
	
	for (int e : answer) cout << e << " ";
}
