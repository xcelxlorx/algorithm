//첫 번째 집에 공유기를 설치함
//가능한 mid 값 중 upper_bound를 찾아야 하므로 end 출력
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, c; cin >> n >> c;
	
	vector<long long> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	long long start = 1000000001, end = v[n - 1] - v[0];
	for (int i = 1; i < n; i++) {
		int temp = v[i] - v[i - 1];
		start = start > temp ? temp : start;
	}

	while (start <= end) {
		long long mid = (start + end) / 2;

		int cnt = 1, prev = v[0];
		for (int i = 1; i < n; i++) {
			if (v[i] - prev >= mid) {
				prev = v[i];
				cnt++;
			}
		}

		if (cnt < c) end = mid - 1;
		else start = mid + 1;
	}

	cout << end;
}
