//큐에 다 넣으면 메모리 초과남(제한: 12MB)

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a; cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (pq.size() < n) pq.push(a);
            else {
                if (pq.top() < a) {
                    pq.pop();
                    pq.push(a);
                }
            }
        }
    }
    cout << pq.top();
}
