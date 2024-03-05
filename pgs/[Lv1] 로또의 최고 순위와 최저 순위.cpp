#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int zero = count(lottos.begin(), lottos.end(), 0);
    int cnt = 0;
    for(int w: win_nums){
        for(int l: lottos){
            if(w == l){
                cnt++; break;
            }
        }
    }
    vector<int> answer;
    answer.push_back(cnt + zero >= 2 ? 7 - (cnt + zero) : 6);
    answer.push_back(cnt >= 2 ? 7 - cnt : 6);
    return answer;
}
