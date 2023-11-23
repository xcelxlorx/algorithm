#include <string>
#include <vector>

using namespace std;

string transfer(int n, int k){
    string result = "";
    while(n > 0){
        result = to_string(n % k) + result;
        n /= k;
    }
    return result;
}

int is_prime(long long n){
    if(n <= 1) return 0;
    for(long long i = 2; i * i <= n; i++) if(n % i == 0) return 0;
    return 1;
}

int solution(int n, int k) {
    string num = transfer(n, k);
    
    int cnt = 0;
    string temp = "";
    for(auto c : num){
        if(c == '0'){
            if(temp != "" && is_prime(stoll(temp))) cnt++;
            temp = "";
        }
        else temp += c;
    }
    if(temp != "" && is_prime(stoll(temp))) cnt++;
    return cnt;
}
