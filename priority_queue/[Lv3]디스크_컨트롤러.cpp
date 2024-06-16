#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());

    int ji = 0;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(int i = ji; i < jobs.size(); i++){
        if(jobs[i][0] != jobs[0][0]) break;
        pq.push({jobs[i][1], jobs[i][0]});
        ji++;
    }

    int t = 0, sum = 0;
    while(!pq.empty()){
        auto v = pq.top();
        pq.pop();

        if(t > v[1]){ //겹쳐져 있음
            sum += v[0] + t - v[1];
            t += v[0];
        }else{ //안겹쳐짐
            sum += v[0];
            t += v[0] + v[1] - t;
        }

        int init = ji;
        for(int i = ji; i < jobs.size(); i++){
            if(jobs[init][0] >= t && (!pq.empty() || jobs[i][0] != jobs[init][0])) break;
            if(jobs[init][0] < t && jobs[i][0] > t) break;
            pq.push({jobs[i][1], jobs[i][0]});
            ji++;
        }
    }

    return sum / jobs.size();
}
