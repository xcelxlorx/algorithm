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

### stringstream
```
#include <sstream>
for(auto record : records){
  stringstream ss(record);
  string time, number, state;
  ss >> time >> number >> state;
}
```

### ceil, floor
```
#include <cmath>
cout << ceil(4.2) << '\n; //5.0
cout << floor(4.2) << '\n; //4.0
```

### map
```
#include <map>
for (const auto& [key, value] : m) {
  cout << "[" << key << "," << value << "]\n";
}
```

### set
```
#include <set>
s.insert(e);
```
