//bfs
//가중치 없는 그래프의 최단 거리
//dfs로 풀면 안됨
#include <vector>
#include <queue>
#include <tuple>
#define INF 987654321
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dist = INF;

void bfs(vector<vector<int>>& maps){
    int n = maps.size(), m = maps[0].size();
    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    
    q.push({0, 0, 1});
    visited[0][0] = 1;
    
    while(!q.empty()){
        int x = get<0>(q.front()), y = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();
        
        if(x == n - 1 && y == m - 1) dist = min(dist, cnt);
        
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(maps[nx][ny] && !visited[nx][ny]){    
                visited[nx][ny] = 1;
                q.push({nx, ny, cnt + 1});
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    bfs(maps);
    return dist == INF ? -1 : dist;
}
