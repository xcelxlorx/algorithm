#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    
    vector<int> answer;
    //set<int> s;
    for(int i = 0; i < numbers.size() - 1; i++){
        for(int j = i + 1; j < numbers.size(); j++){
            answer.push_back(numbers[i] + numbers[j]);
            //s.insert(numbers[i] + numbers[j]);
        }
    }
    
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    //answer.assign(s.begin(), s.end());
    return answer;
}
