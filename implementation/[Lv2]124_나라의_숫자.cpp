//3진법
#include <string>
#include <iostream>

using namespace std;

char m[3] = {'4', '1', '2'};

string solution(int n) {
    string answer = "";
    while(n > 0){
        int d = n % 3;
        n /= 3;
        if(d == 0) n -= 1; //4일 경우 앞자리에서 가져다 씀
        answer = m[d] + answer;
    }
    return answer;
}
