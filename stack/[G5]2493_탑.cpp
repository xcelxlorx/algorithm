//스택 O(N)
//새로 들어온 탑의 높이보다 바로 이전 높이가 작으면 이전 탑은 사용되지 않음 
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, a; cin >> n;

	vector<int> answer(n + 1, 0);
	stack<vector<int>> st;
	st.push({ 100000001, 0 }); //높이, 탑 번호
	
	for (int i = 1; i <= n; i++) {
		cin >> a;
		while (st.top()[0] < a) st.pop();
		answer[i] = st.top()[1];
		st.push({a, i}); 
	}

	for (int i = 1; i <= n; i++) cout << answer[i] << " ";
}
