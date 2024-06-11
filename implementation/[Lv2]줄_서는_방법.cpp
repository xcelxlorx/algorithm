#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> v;
    for(int i = 1; i <= n; i++) v.push_back(i);
    
    long long f = 1;
    for(int i = 1; i < n; i++) f *= i; //(n-1)!
    
    vector<int> answer;
    for(int i = n; i > 1; i--){
        if(f == 0) break;
        long long idx = (k - 1) / f;
        idx %= v.size();
        answer.push_back(v[idx]);
        v.erase(v.begin() + idx);
        f /= (i - 1);
    }
    answer.push_back(v[0]);
    return answer;
}
