//자릿수
#include <iostream>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey > 0){
        int r = storey % 10;
        answer += min(r, 10 - r);
        storey /= 10;
        if(r >= 6) storey++;
        if(r == 5 && storey % 10 >= 5) storey++;
    }
    return answer;
}
