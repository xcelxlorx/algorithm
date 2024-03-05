#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    vector<char> vx, vy;
    for(char c : X) vx.push_back(c);
    for(char c : Y) vy.push_back(c);
    
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    
    vector<char> vn(vx.size() + vy.size());
    auto iter = set_intersection(vx.begin(), vx.end(), vy.begin(), vy.end(), vn.begin());
    vn.erase(iter, vn.end());
    
    string answer = "";
    for(char c : vn) answer += c;
    sort(answer.begin(), answer.end(), greater<char>());
    
    if(answer == "") return "-1";
    if(answer[0] == '0') return "0";
    return answer;
}
