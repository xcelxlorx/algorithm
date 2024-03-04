#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    for(string s : babbling){
        int prev = -1;
        int i = 0;
        while(i < s.size()){
            if(s.substr(i, 3) == "aya" && prev != 1){
                s.replace(i, 3, "");
                prev = 1;
            }
            else if(s.substr(i, 2) == "ye" && prev != 2){
                s.replace(i, 2, "");
                prev = 2;
            }
            else if(s.substr(i, 3) == "woo" && prev != 3){
                s.replace(i, 3, "");
                prev = 3;
            }
            else if(s.substr(i, 2) == "ma" && prev != 4){
                s.replace(i, 2, "");
                prev = 4;
            }else i++;
        }  
        if(s == "") answer++;
    }
    return answer;
}
