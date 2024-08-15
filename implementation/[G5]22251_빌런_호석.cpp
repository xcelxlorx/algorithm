#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k, p, x; cin >> n >> k >> p >> x;
    vector<vector<bool>> led(10, vector<bool>(7));
    led[0] = {1,1,1,0,1,1,1};
    led[1] = {0,0,1,0,0,1,0};
    led[2] = {1,0,1,1,1,0,1};
    led[3] = {1,0,1,1,0,1,1};
    led[4] = {0,1,1,1,0,1,0};
    led[5] = {1,1,0,1,0,1,1};
    led[6] = {1,1,0,1,1,1,1};
    led[7] = {1,0,1,0,0,1,0};
    led[8] = {1,1,1,1,1,1,1};
    led[9] = {1,1,1,1,0,1,1};

    int cur = 1, cnt = 0;
    while(cur <= n){
        int xc = x, cc = cur, diff = 0;
        for(int i = 0; i < k; i++){
            for(int j = 0; j < 7; j++){
                if(led[xc % 10][j] ^ led[cc % 10][j]) diff++;
            }
            xc /= 10; cc /= 10;
        }
        if(diff <= p && diff >= 1) cnt++;
        cur++;
    }
    cout << cnt;
}
