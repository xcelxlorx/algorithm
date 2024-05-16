//최초로 나오는 0의 위치와 그 다음 1의 위치만 바꾸면 됨
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long n : numbers){
        long long zero = 1;
        while((n & zero) > 0) zero <<= 1;
        answer.push_back(n + zero - (zero >> 1));
    }
    return answer;
}
