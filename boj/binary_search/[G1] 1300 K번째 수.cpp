//중앙값보다 작은 수의 개수가 k-1개일 경우 정답
//배열 값이 배수라는 것을 고려
#include <iostream>

using namespace std;

int binary_search(long long n, long long k) {
	long long start = 1, end = k;

	while (start <= end) {
		long long mid = (start + end) / 2;

		long long cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}

		if (cnt >= k) end = mid - 1;
		else if (cnt < k) start = mid + 1;
	}

	return start;
}

int main() {
	long long n, k; cin >> n >> k;
	cout << binary_search(n, k) << '\n';
}
