#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int sum = 0;
    for(int i = 0; i <= 9; i++) {
        auto it = find_if(numbers.begin(), numbers.end(), [&](const auto &e){ return e == i; });
        if(it == numbers.end()) sum += i;
    }
    return sum;
}
