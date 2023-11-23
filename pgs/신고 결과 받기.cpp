#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, set<string>> to;
    for(auto e : report){
        stringstream ss(e);
        string u1, u2;
        ss >> u1 >> u2;
        to[u2].insert(u1);
    }
    
    map<string, int> from;
    for(auto &[key, value] : to){
        if(value.size() >= k){
            for(auto e : value) from[e]++;
        }
    }
    
    vector<int> answer;
    for(auto e : id_list) answer.push_back(from[e]);
    return answer;
}
