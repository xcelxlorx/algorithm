#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    vector<string> v1, v2;
    for(int i = 1; i < str1.size(); i++) {
        if(!isalpha(str1[i]) || !isalpha(str1[i-1])) continue;
        v1.push_back(str1.substr(i-1, 2));
    }
    for(int i = 1; i < str2.size(); i++) {
        if(!isalpha(str2[i]) || !isalpha(str2[i-1])) continue;
        v2.push_back(str2.substr(i-1, 2));
    }
    
    sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());
    
    vector<string> u(v1.size() + v2.size()), inter(v1.size() + v2.size());
    auto iter = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), u.begin());
    u.erase(iter, u.end());
    iter = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inter.begin());
    inter.erase(iter, inter.end());
    
    return u.size() != 0 ? (double)inter.size() / u.size() * 65536 : 65536;
}
