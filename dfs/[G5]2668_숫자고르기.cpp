//방향 그래프에서 사이클 찾기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, cur;
vector<bool> visited;

bool find_cycle(int first, int node){
    if(cur[node]) return first == node;
    cur[node] = 1;
    int next = v[node];
    if(find_cycle(first, next)) return 1;
    return 0;
}

int main(){
    int n; cin >> n;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    visited.resize(n + 1, 0);
    vector<int> answer;
    for(int node = 1; node <= n; node++){
        cur = vector<int>(n + 1, 0);
        if(!visited[node] && find_cycle(node, node)){
            for(int i = 1; i <= n; i++){
                if(cur[i]){
                    answer.push_back(i); //방문 노드들 추가
                    visited[i] = 1;
                }
            }
        }
    }

    cout << answer.size() << '\n';
    sort(answer.begin(), answer.end());
    for(int e : answer) cout << e << '\n';
}
