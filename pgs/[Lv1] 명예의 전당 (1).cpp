#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> answer;
    for(int e : score){
        if(pq.size() < k) pq.push(e);
        else {
            if(pq.top() < e){
                pq.pop();
                pq.push(e);
            }
        }
        answer.push_back(pq.top());
    }
    return answer;
}
