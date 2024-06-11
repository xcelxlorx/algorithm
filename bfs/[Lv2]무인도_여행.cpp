#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<bool>> visited;
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int sx, int sy, vector<string>& maps){
    queue<vector<int>> q;
    int cnt = 0;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    
    while(!q.empty()){
        auto v = q.front();
        int x = v[0], y = v[1];
        q.pop();
        
        cnt += maps[x][y] - 0x30;
        
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(!visited[nx][ny] && maps[nx][ny] != 'X'){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
    
    return cnt;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = maps.size(); m = maps[0].size();
    visited = vector<vector<bool>>(n, vector<bool>(m, 0));
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].size(); j++){
            if(maps[i][j] != 'X' && !visited[i][j]){
                int cnt = bfs(i, j, maps);
                answer.push_back(cnt);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}
