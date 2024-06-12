//mst
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> nodes;

int prim(int n){
    priority_queue<pair<int, int>> pq;
    vector<bool> visited(n, 0);
    int cost = 0;
    pq.push({0, 0});
    
    while(!pq.empty()){
        int cur_cost = -pq.top().first, cur_node = pq.top().second;
        pq.pop();
        
        if(visited[cur_node]) continue;
        visited[cur_node] = 1;
        cost += cur_cost;
        
        for(auto p : nodes[cur_node]){
            if(!visited[p.first]){
                pq.push({-p.second, p.first});
            }
        }
    }
    return cost;
}

int solution(int n, vector<vector<int>> costs) {
    nodes.resize(n);
    for(auto v : costs){
        nodes[v[0]].push_back({v[1], v[2]});
        nodes[v[1]].push_back({v[0], v[2]});
    }
    return prim(n);
}
