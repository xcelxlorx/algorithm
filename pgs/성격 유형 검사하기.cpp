/*
2022 KAKAO TECH INTERNSHIP
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    map<char, int> m;
    
    for(int i = 0; i < survey.size(); i++){
        int choice = choices[i];
        if(choice > 4) m[survey[i][1]] += choice - 4;
        else m[survey[i][0]] += 4 - choice;
    }
    
    string answer = "";
    answer += m['R'] >= m['T'] ? 'R' : 'T';
    answer += m['C'] >= m['F'] ? 'C' : 'F';
    answer += m['J'] >= m['M'] ? 'J' : 'M';
    answer += m['A'] >= m['N'] ? 'A' : 'N';
    
    return answer;
}
