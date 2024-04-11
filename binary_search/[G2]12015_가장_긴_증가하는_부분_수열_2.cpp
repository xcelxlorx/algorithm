//LIS
//1) dp: N^2 -> 시간 초과
//2) 이분 탐색 - lower_bound: NlogN
#include <iostream>
#include <vector>

using namespace std;

vector<int> x;

int binary_search(int target) {
	int start = 1, end = x.size() - 1;

	while (start < end) {
		int mid = (start + end) / 2;
		
		if (x[mid] >= target) end = mid;
		else start = mid + 1;
	}

	return end;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector<int> v(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> v[i];
	
	//1) dp 
	/*
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << dp[n];
	*/
	
	//2) binary_search - lower_bound
	x.resize(1, 0);
	for (int i = 1; i <= n; i++) {
		if (x.back() < v[i]) x.push_back(v[i]);
		else {
			//2-1) STL 사용
			int idx = lower_bound(x.begin(), x.end(), v[i]) - x.begin(); 
			
			//2-2) binary_search를 이용해서 lower_bound 구현
			//int idx = binary_search(v[i]); 

			x[idx] = v[i];
		}
	}

	cout << x.size() - 1;
}
