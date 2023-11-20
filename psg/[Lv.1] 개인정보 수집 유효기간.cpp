/*
2023 KAKAO BLIND RECRUITMENT
*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#define MONTH 12
#define DAY 28

using namespace std;

int calculate(string date){
    int result = 0;
    result += stoi(date.substr(0, 4)) * DAY * MONTH;
    result += stoi(date.substr(5, 2)) * DAY;
    result += stoi(date.substr(8, 2));
    return result;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int day = calculate(today);
    
    map<char, int> map; 
    for(string term : terms){
        map[term[0]] = stoi(term.substr(2));
    }

    for(int i = 0; i < privacies.size(); i++){
        int privacy = calculate(privacies[i]);
        privacy += map[privacies[i][11]] * DAY;
        privacy--;
        
        if(privacy < day){
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}
