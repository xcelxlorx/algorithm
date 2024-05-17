#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 987654321};
    int sum = sequence[0], b = 0, e = 0;
    while(b <= e && e < sequence.size()){
        if(sum == k){
            int prev = answer[1] - answer[0];
            int cur = e - b;
            if((prev > cur) || ((prev == cur) && (b < answer[0]))){
                answer = {b, e};
            }
            sum -= sequence[b++];
        }
        else if(sum < k) sum += sequence[++e];
        else if(sum > k) sum -= sequence[b++];
    }
    return answer;
}
