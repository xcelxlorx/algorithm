#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2){
    return p1.second > p2.second;
}

vector<int> solution(string s) {
    for(int i = 0; i < s.size(); i++) if(!isdigit(s[i])) s.replace(i, 1, " ");
    
    map<string, int> m;
    stringstream ss(s); string num;
    while(ss >> num) m[num]++;
    
    vector<pair<string, int>> v;
    for(auto it = m.begin(); it != m.end(); it++){
        v.push_back({it->first, it->second});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    vector<int> answer;
    for(auto p : v) answer.push_back(stoi(p.first));
    return answer;
}
