#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long b = 1, e = 1e18, mid;
    while(b <= e){
        mid = (b + e) / 2;
        long long cnt = 0;
        for(int t : times) cnt += mid / t;
        if(cnt < n) b = mid + 1;
        else e = mid - 1;
    }
    return e + 1;
}
