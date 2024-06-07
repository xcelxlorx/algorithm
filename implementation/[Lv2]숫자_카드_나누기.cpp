//최대공약수만 확인하면 됨
#include <vector>

using namespace std;

int gcd(int n1, int n2){
    int a = max(n1, n2), b = min(n1, n2);
    while(b > 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int check(vector<int> &v1, vector<int> &v2){
    int ga = v1[0];
    for(int e : v1) ga = gcd(ga, e);
    for(int e : v2) if(e % ga == 0) return 0;
    return ga;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    return max(check(arrayA, arrayB), check(arrayB, arrayA));
}
