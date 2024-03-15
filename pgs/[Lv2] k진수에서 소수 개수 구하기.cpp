#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool isPrime(long long n){
    if(n == 1) return 0;
    for(long long i = 2; i * i <= n; i++) if(n % i == 0) return 0;
    return 1;
}

int solution(int n, int k) {
    string s = "";
    while(n > 0){
        s = to_string(n % k) + s;
        n /= k;
    }
    
    for(int i = 0; i < s.size(); i++) if(s[i] == '0') s[i] = ' ';
    
    stringstream ss(s); string prime;
    int answer = 0;
    while(ss >> prime) if(isPrime(stoll(prime))) answer++;
    return answer;
}
