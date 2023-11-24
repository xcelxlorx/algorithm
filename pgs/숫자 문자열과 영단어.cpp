/*
카카오 채용연계형 인턴십
*/
#include <string>

using namespace std;

string replace_all(string str, string from, string to){
    int pos = 0;
    while((pos = str.find(from, pos)) != string::npos){
        str.replace(pos, from.length(), to);
        pos += to.length();
    }
    return str;
}

int solution(string s) {
    s = replace_all(s, "zero", "0");
    s = replace_all(s, "one", "1");
    s = replace_all(s, "two", "2");
    s = replace_all(s, "three", "3");
    s = replace_all(s, "four", "4");
    s = replace_all(s, "five", "5");
    s = replace_all(s, "six", "6");
    s = replace_all(s, "seven", "7");
    s = replace_all(s, "eight", "8");
    s = replace_all(s, "nine", "9");
    return stoi(s);
}
