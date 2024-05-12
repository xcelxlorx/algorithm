#include <string>
#include <vector>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dir(char d){
    if(d == 'U') return 0;
    else if(d == 'D') return 1;
    else if(d == 'R') return 2;
    else return 3;
}

int solution(string dirs) {
    int visited[11][11][11][11] = {0, };
    int x = 5, y = 5; //시작
    int cnt = 0;
    
    for(char e : dirs){ 
        int d = dir(e);
        int nx = x + dx[d], ny = y + dy[d];
        if(nx < 0 || nx > 10 || ny < 0 || ny > 10) continue;
        if(!visited[x][y][nx][ny] && !visited[nx][ny][x][y]){
            cnt++;
            visited[x][y][nx][ny] = 1;
        }
        x = nx; y = ny;
    }
    return cnt;
}
