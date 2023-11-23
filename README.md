# algorithm
## STL
### queue
```
#include <queue>
queue<int> q1(deque<int>(v.begin(), v.end())); //벡터로 초기화
```
### accumulate
```
#include <numeric>
long long sum1 = accumulate(v.begin(), v.end(), 0LL);
```
### to_string
```
#include <string>
string result = to_string(n);
```

### stoi, stol, stoll, stof, stod
```
#include <string>
int i = stoi(s);
long l = stol(s);
long long ll = stoll(s);
float f = stof(s);
double d = stod(s);
```
