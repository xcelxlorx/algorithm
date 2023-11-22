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
