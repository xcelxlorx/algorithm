#include <algorithm> 
#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    long long fee = 1ll * count * (count + 1) / 2 * price ;
    return max(fee - money, 0ll);
}
