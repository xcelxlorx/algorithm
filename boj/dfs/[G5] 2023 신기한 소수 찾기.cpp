#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> answer;
int n;

bool is_prime(int n) {
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

void dfs(string s) {
	if (s.size() == n) {
		answer.push_back(s);
		cout << s << '\n';
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (i % 2 == 0) continue;
		string ns = s + to_string(i);
		if (is_prime(stoi(ns))) {
			dfs(ns);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	dfs("2"); dfs("3"); dfs("5"); dfs("7");
}
