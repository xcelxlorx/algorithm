/*
 2021 KAKAO BLIND RECRUITMENT
*/
#include <string>
#include <vector>
#include <regex>

using namespace std;

string solution(string new_id) {
    //step 1
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    //step 2
    bool b = isalnum(new_id[0]);
    new_id.erase(remove_if(new_id.begin(), new_id.end(), [](char c){
        return !(isalnum(c) || c == '-' || c == '.' || c == '_');
    }), new_id.end());
    //step 3
    new_id = regex_replace(new_id, regex("\\.+"), ".");
    //step 4
    new_id = regex_replace(new_id, regex("^\\."), "");
    new_id = regex_replace(new_id, regex("\\.$"), "");
    //step 5
    if(new_id == "") new_id = 'a';
    //step 6
    new_id = new_id.substr(0, 15);
    new_id = regex_replace(new_id, regex("\\.$"), "");
    //step 7
    while(new_id.length() < 3) new_id += new_id.back();
    return new_id;
}
