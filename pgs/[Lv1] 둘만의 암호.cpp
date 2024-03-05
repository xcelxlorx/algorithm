#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    vector<char> v;
    for(char c = 'a' ; c <= 'z'; c++){
        if(find(skip.begin(), skip.end(), c) == skip.end()){
            v.push_back(c);
        }
    }
    
    string answer = "";
    for(char c : s){
        int idx = (find(v.begin(), v.end(), c) - v.begin() + index) % v.size();
        answer += v[idx];
    }
    return answer;
}
