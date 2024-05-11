//s[3] - s[2] = k
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n, k; cin >> n >> k;

	long long cnt = 0;
	vector<long long> s(n + 1, 0);
	map<long long, int> m;
	m[0] = 1;
	
	for (long long i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] += s[i - 1];
		cnt += m[s[i] - k]; //차이가 k인 어떤 누적합이 존재하는지
		m[s[i]]++; //현재 누적합이 존재한다고 추가
	}

	cout << cnt;
}
