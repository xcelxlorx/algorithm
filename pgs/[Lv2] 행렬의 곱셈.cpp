#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(auto a : arr1){
        vector<int> v;
        for(int j = 0; j < arr2[0].size(); j++){
            int sum = 0;
            for(int i = 0; i < arr2.size(); i++){
                sum += a[i] * arr2[i][j];
            }
            v.push_back(sum);
        }
        answer.push_back(v);
    }
    return answer;
}
