#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

int transfer(string time){
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

int get_time(string start, string end){
    return transfer(end) - transfer(start);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> times;
    map<string, string> in;
    
    for(auto record : records){
        stringstream ss(record);
        string time, number, state;
        ss >> time >> number >> state;
        
        if(state == "IN") in[number] = time;
        else if(state == "OUT") {
            times[number] += get_time(in[number], time);
            in[number] = "";
        }
    }

    for (const auto& [key, value] : in) {
        if(value != "") times[key] += get_time(value, "23:59");
    }
    
    vector<int> answer;
    for (const auto& [key, value] : times) {
        int price = fees[1];
        if(value > fees[0]) price += ceil((double)(value - fees[0]) / fees[2]) * fees[3];
        answer.push_back(price);
    }
    return answer;
}
