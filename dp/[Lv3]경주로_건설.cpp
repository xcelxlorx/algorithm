//3차원 dp + bfs
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(vector<vector<int>>& board){
    queue<vector<int>> q;
    q.push({0, 0, 0}); q.push({0, 0, 1}); //x y 방향
    int n = board.size();
    vector<vector<vector<int>>> cost(n, vector<vector<int>>(n, vector<int>(2, INF)));
    cost[0][0][0] = 0; cost[0][0][1] = 0;
    
    while(!q.empty()){
        auto v = q.front();
        int x = v[0], y = v[1], d = v[2], c = cost[x][y][d];
        q.pop();
        
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(board[nx][ny]) continue;
            
            int next_d = k <= 1 ? 0 : 1;
            int next_cost = cost[nx][ny][next_d];
            if(next_d ^ d) next_cost = min(next_cost, c + 600);
            else next_cost = min(next_cost, c + 100);
            
            if(next_cost < cost[nx][ny][next_d]){
                q.push({nx, ny, next_d});
                cost[nx][ny][next_d] = next_cost;
            }
        }
    }

    return min(cost[n - 1][n - 1][0], cost[n - 1][n - 1][1]);
}

int solution(vector<vector<int>> board) {
    return bfs(board);
}
