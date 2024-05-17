#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, i = 1, si = 0;
    while(i <= n){
        if(i < stations[si] - w || i > stations[si] + w){ 
            answer++;
            i += w * 2 + 1;  
        }else i = stations[si] + w + 1;
        
        if(i > stations[si] + w) si++;
    }
    return answer;
}
