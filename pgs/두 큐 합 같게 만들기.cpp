/*
2022 KAKAO TECH INTERNSHIP
*/
#include <string>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1(deque<int>(queue1.begin(), queue1.end()));
    queue<int> q2(deque<int>(queue2.begin(), queue2.end()));
    
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);
    
    if((sum1 + sum2) % 2 == 1) return -1;
    
    int cnt = 0;
    while(sum1 != sum2){
        if(cnt > queue1.size() * 3) return -1;

        if(sum1 > sum2){
            int e = q1.front();
            q2.push(e);
            q1.pop();
            sum1 -= e; sum2 += e;
            cnt++;
        }
        if(sum1 < sum2){
            int e = q2.front();
            q1.push(e);
            q2.pop();
            sum1 += e; sum2 -= e;
            cnt++;
        }
    }
    
    return cnt;
}
