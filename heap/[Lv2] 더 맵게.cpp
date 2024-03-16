#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> s, int K) {
    priority_queue<int> pq;
    for(auto e : s) pq.push(-e);
    
    int answer = 0;
    while(!pq.empty()){
        int top = -pq.top();
        if(top >= K) break;
        pq.pop();
        if(pq.empty()) return -1;
        
        int top2 = -pq.top();
        pq.pop();
        pq.push(-(top + top2 * 2));
        answer++;
    }
    
    return answer;
}
