#include <string>
#include <vector>

using namespace std;

int one = 0, zero = 0;

void divide_and_conquer(int n, int x, int y, vector<vector<int>>& arr){
    if(n == 1){
        if(arr[x][y]) one++;
        else zero++;
        return;
    }
    
    bool flag = true;
    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(arr[x][y] != arr[i][j]){
                flag = false;
                break;
            }
        }
    }
    
    if(flag){
        if(arr[x][y] == 1) one++;
        else zero++;
        return;
    }
    
    divide_and_conquer(n/2, x, y, arr);
    divide_and_conquer(n/2, x + n/2, y, arr);
    divide_and_conquer(n/2, x, y + n/2, arr);
    divide_and_conquer(n/2, x + n/2, y + n/2, arr);
}

vector<int> solution(vector<vector<int>> arr) {
    divide_and_conquer(arr.size(), 0, 0, arr);
    return {zero, one};
}
