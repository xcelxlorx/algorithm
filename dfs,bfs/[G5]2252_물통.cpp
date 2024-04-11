#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

set<int> answer;
int buckets[3];
int dx[6] = { 0, 0, 1, 1, 2, 2 };
int dy[6] = { 1, 2, 0, 2, 0, 1 };
vector<vector<bool>> visited; //A, B

void bfs() {
	queue<vector<int>> q;
	q.push({ 0, 0, buckets[2] });
	visited[0][0] = 1;
	answer.insert(buckets[2]);
	
	while (!q.empty()) {
		vector<int> cur = q.front();
		q.pop();

		for (int k = 0; k < 6; k++) {
			vector<int> next = cur;
			int sender = dx[k], receiver = dy[k];
			
			int move = min(buckets[receiver] - cur[receiver], cur[sender]);
			next[sender] = cur[sender] - move;
			next[receiver] = cur[receiver] + move;

			if (!visited[next[0]][next[1]]) {
				if (next[0] == 0) answer.insert(next[2]);
				visited[next[0]][next[1]] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	cin >> buckets[0] >> buckets[1] >> buckets[2];

	visited = vector<vector<bool>>(buckets[2] + 1, vector<bool>(buckets[2] + 1, 0));

	bfs();

	for (auto e : answer) cout << e << " ";
}
