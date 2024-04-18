//map에 자리수마다 번호를 저장함
//전화번호 목록을 다시 반복하면서 map에 1 이상인지 확인
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; 
		string s;
		map<string, int> m;
		vector<string> v(n);

		for (int i = 0; i < n; i++) {
			cin >> s;
			v[i] = s;
			string temp = "";
			for (int j = 0; j < s.size(); j++) {
				temp += s[j];
				m[temp]++;
			}
		}

		bool c = 1;
		for (string e : v) {
			if (m[e] > 1) {
				c = 0;
				break;
			}
		}

		if (c) cout << "YES\n";
		else cout << "NO\n";
	}
}
