#include <string>
#include <queue>
#include <vector>

using namespace std;

int sx, sy, lx, ly, ex, ey;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;

int bfs(int x1, int y1, int x2, int y2, vector<string>& maps){
    queue<vector<int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    q.push({x1, y1, 0});
    visited[x1][y1] = 1;
    
    while(!q.empty()){
        auto v = q.front();
        int x = v[0], y = v[1], t = v[2];
        q.pop();
        
        if(x == x2 && y == y2) return t;
        
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(!visited[nx][ny] && maps[nx][ny] != 'X'){
                q.push({nx, ny, t + 1});
                visited[nx][ny] = 1;
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    n = maps.size(); m = maps[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maps[i][j] == 'S'){
                sx = i; sy = j;
            }
            if(maps[i][j] == 'L'){
                lx = i; ly = j;
            }
            if(maps[i][j] == 'E'){
                ex = i; ey = j;
            }
        }
    }
    
    int ld = bfs(sx, sy, lx, ly, maps);
    if(ld == -1) return -1;
    int ed = bfs(lx, ly, ex, ey, maps);
    if(ed == -1) return -1;
    return ld + ed;
}
