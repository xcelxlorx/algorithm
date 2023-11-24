/*
2019 카카오 겨울 인턴십
*/
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <map>

using namespace std;

vector<int> solution(string s) {
    s = regex_replace(s, regex("\\{"), "");
    s = regex_replace(s, regex("\\}"), "");
    s = regex_replace(s, regex("\\,"), " ");

    map<string, int> m;
    stringstream ss(s);
    string n;
    while(ss >> n) m[n]++;
    
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b){
        return a.second > b.second;
    });
    
    vector<int> answer;
    for(auto e : v) answer.push_back(stoi(e.first));
    return answer;
}
