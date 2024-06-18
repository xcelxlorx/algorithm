//nlogk 5*10^9 ?
#include <queue>
#include <vector>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int lv = 0;
    long long sum = 0;
    while(lv < enemy.size()){
        if(pq.size() < k) pq.push(enemy[lv]);
        else{
            if(pq.top() < enemy[lv]){
                sum += pq.top();
                pq.pop();
                pq.push(enemy[lv]);
            }else sum += enemy[lv];
        }
        if(sum > n) break;
        lv++;
    }
    return lv;
}
