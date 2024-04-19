//내림차순 정렬
//로프 개수를 1 ~ k개만큼 선택함
//가장 작은 중량 * k로 갱신
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end(), greater<int>());

	int answer = 0;
	for (int k = 1; k <= n; k++) {
		answer = max(answer, v[k - 1] * k);
	}
	cout << answer;
}
