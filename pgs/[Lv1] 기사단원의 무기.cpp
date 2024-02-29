//약수의 개수
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int div(int n){
    int cnt = 0;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0) {
            if(i * i == n) cnt++;
            else cnt += 2;
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i = 1; i <= number; i++){
        int d = div(i);
        answer += d <= limit ? d : power;
    }
    return answer;
}
