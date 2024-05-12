#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int n = land.size();
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 4; j++){
            int max_value = 0;
            for(int k = 0; k < 4; k++){
                if(j == k) continue;
                max_value = max(max_value, land[i - 1][k]);
            }
            land[i][j] += max_value;
        }
    }
    
    return max({land[n - 1][0], land[n - 1][1], land[n - 1][2], land[n - 1][3]});
}
