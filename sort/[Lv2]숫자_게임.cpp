#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int score = 0, bi = B.size() - 1;
    for(int i = A.size() - 1; i >= 0; i--){
        if(A[i] < B[bi]){
            score++; bi--;
        }
    }
    return score;
}
