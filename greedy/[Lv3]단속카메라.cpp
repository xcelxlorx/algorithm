//나간 시점 기준 정렬
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), cmp);
    
    int camera = routes[0][1], cnt = 1;
    for(int i = 0; i < routes.size(); i++){
        if(routes[i][0] > camera){
            camera = routes[i][1];
            cnt++;
        }
    }
    
    return cnt;
}
