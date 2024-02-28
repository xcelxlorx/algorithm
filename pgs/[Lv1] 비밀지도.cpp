//2018 KAKAO BLIND RECRUITMENT
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++){
        int num = arr1[i] | arr2[i];
        string cur = "";
        for(int j = 0; j < n; j++){
            cur = (num % 2 == 0) ? " " + cur : "#" + cur;
            num /= 2;
        }
        answer.push_back(cur);
    }
    return answer;
}
