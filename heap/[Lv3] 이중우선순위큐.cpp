#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> pq1, pq2;
    int size = 0;
    
    for(string operation : operations){
        stringstream ss(operation);
        string op, num; ss >> op >> num;
        
        if(size == 0) {
            pq1 = priority_queue<int>();
            pq2 = priority_queue<int>();
        }
        
        if(op == "I"){
            pq1.push(stoi(num)); pq2.push(-stoi(num)); 
            size++;
        }else{
            if(size == 0) continue;
            if(num == "1") pq1.pop();
            else pq2.pop();
            size--;
        }
    }
    if(size == 0) return {0, 0};
    else return {pq1.top(), -pq2.top()};
}
