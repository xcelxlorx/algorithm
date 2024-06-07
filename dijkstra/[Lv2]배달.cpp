#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

vector<vector<pair<int, int>>> nodes;
vector<int> dist;

void dijkstra(int n){
    priority_queue<pair<int, int>> pq;
    vector<bool> visited(n + 1, 0);
    dist = vector<int>(n + 1, INF);
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        int cost = -pq.top().first, cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < cost) continue;
        if(visited[cur]) continue;
        visited[cur] = 1;
        
        for(auto p : nodes[cur]){
            int next = p.first, d = p.second;
            if(dist[cur] + d < dist[next]){
                dist[next] = dist[cur] + d;
                pq.push({-dist[next], next});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    nodes.resize(N + 1);
    
    for(auto v : road){
        nodes[v[0]].push_back({v[1], v[2]});
        nodes[v[1]].push_back({v[0], v[2]});
    }
    
    dijkstra(N);
    
    int cnt = 0;
    for(int i = 1; i <= N; i++) if(dist[i] <= K) cnt++;
    return cnt;
}
