#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    int mid = s / n;
    if(mid == 0) return {-1};
    
    vector<int> v(n, mid);
    int sum = mid * n;
    int diff = abs(s - sum);
    if(sum < s){
        int i = n - 1;
        while(diff--) v[i--]++; //뒤에서 1씩 추가
    }else if(sum > s){
        int i = 0;
        while(diff--) v[i++]--; //앞에서 1씩 빼기
    }
    return v;
}
