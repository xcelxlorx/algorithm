/*
2019 카카오 겨울 인턴십
*/
#include <string>
#include <vector>
#include <stack>

using namespace std;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for(auto col : moves){
        for(int row = 0; row < board.size(); row++){
            if(board[row][col - 1] != 0){
                if(s.size() > 0 && s.top() == board[row][col - 1]){
                    s.pop(); answer++;
                }else {
                  s.push(board[row][col - 1]);
                }
                board[row][col - 1] = 0;
                break;
            }
        }
    }
    return answer * 2;
}
