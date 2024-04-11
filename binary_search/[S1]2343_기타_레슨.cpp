//start, end를 잘 정해야 함
//각 강의를 하나씩 담을 수 있으므로 start 초기값은 강의의 최대값
//모든 강의를 하나의 블루레이에 담을 수 있으므로 end 초기값은 강의의 합
//start 출력

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int binary_search(int start, int end, int m) {
	while (start <= end) {
		int mid = (start + end) / 2;

		int cnt = 1, sum = 0;
		for (int i = 0; i < v.size(); i++) {
			if (sum + v[i] > mid) {
				cnt++;
				sum = v[i];
			}
			else sum += v[i];
		}

		if (cnt <= m) end = mid - 1;
		else if (cnt > m) start = mid + 1;
	}

	return start;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a; cin >> n >> m;

	int sum = 0, max_value = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum += a;
		max_value = max_value < a ? a : max_value;
		v.push_back(a);
	}

	cout << binary_search(max_value, sum, m) << '\n';
}
