#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> pb) {
    map<string, int> m;
    for(string s : pb) for(int i = 0; i < s.size(); i++) m[s.substr(0, i + 1)]++;
    for(string s : pb) if(m[s] > 1) return false;
    return true;
}
