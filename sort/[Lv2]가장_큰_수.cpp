#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(int n1, int n2){
    string a = to_string(n1), b = to_string(n2);
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    for(auto e : numbers) answer += to_string(e);
    return answer[0] == '0' ? "0" : answer;
}
