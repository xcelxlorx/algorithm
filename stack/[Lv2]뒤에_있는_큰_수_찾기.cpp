//stack
//top이 뒷 큰수가 됨
//top보다 numbers가 클 경우, top은 이전 수의 뒷 큰수가 될 수 없으므로 pop 

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> st;
    
    for(int i = numbers.size() - 1; i >= 0; i--){
        while(1){
            if(st.empty()){
                answer.push_back(-1);
                break;
            }
            if(numbers[st.top()] > numbers[i]){
                answer.push_back(numbers[st.top()]);
                break;
            }else{
                st.pop();
            }
        }
        st.push(i);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
