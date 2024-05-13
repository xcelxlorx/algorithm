#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    map<int, int> m1, m2;
    for(int e : topping) m1[e]++;
    int cnt = 0;
    for(int e: topping){
        m1[e]--; m2[e]++;
        if(m1[e] == 0) m1.erase(e);
        if(m1.size() == m2.size()) cnt++;
    }
    return cnt;
}
