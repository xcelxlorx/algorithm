//최종 주가보다 작으면 주식을 사고, 다시 최종 주가를 찾음
//역방향으로 푸는게 편함
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];

		int max = v[n - 1];
		long long gain = 0;
		for (int i = n - 2; i >= 0; i--) {
			if (max >= v[i]) gain += max - v[i];
			else max = v[i];
		}
		cout << gain << '\n';

		/*queue<int> q;
		for (int i = 10000; i >= 0; i--) {
			if (stock[i] != -1) q.push(stock[i]);
		}

		long long loss = 0, gain = 0, cnt = 0;
		int m = q.front(); 
		q.pop();
		
		for (int i = 0; i < n; i++) {
			if (i < m) {
				loss += v[i]; 
				cnt++;
			}
			else if(i == m){
				gain += v[i] * cnt;
				cnt = 0;
				while (!q.empty()) {
					if (q.front() < m) q.pop();
					else {
						m = q.front();
						q.pop();
						break;
					}
				}	
			}
		}
		cout << gain - loss << '\n';*/
	}
}
