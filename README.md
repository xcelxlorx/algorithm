# algorithm
## util
### 시간 단축
```
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```
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
###  string: front, back, to_string
```
#include <string>
string s = to_string("12345");
char c = s.front(); //맨 앞 문자
c = s.back(); //맨 뒤 문자
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

//공백을 기준으로 반복
while(ss >> s){}
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

### transform
특정 함수를 사용해서 값을 변경
```
#include <algorithm> //없어도 됨
transform(s.begin(), s.end(), s.begin(), ::tolower);
```

### erase & remove_if
```
//erase
auto it = min_element(arr.begin(), arr.end());
arr.erase(it);

s.erase(remove_if(s.begin(), s.end(), [](char c){
  return c == '.';
}), s.end());
```

### isalpha, isdigit, isalnum, islower, isupper, isblank
```
#include <cctype> //없어도 됨
bool b = isalpha('A');
b = isdigit('A');
b = isalnum('A');
b = islower('A');
b = isupper('A');
b = isblank('A'); //공백 체크
```

### toupper, tolower
```
char c = toupper('a');
c = tolower('A');
```

### regex
특수문자는 이스케이프 문자 붙여주기!
```
#include <regex>
s = regex_replace(s, regex("\\.+"), "."); //.이 1개 이상 있을 경우
s = regex_replace(s, regex("^\\."), ""); //맨 앞에 .이 있을 경우
s = regex_replace(s, regex("\\.$"), ""); //맨 뒤에 .이 있을 경우
```

### binary_search
```
cout << binary_search(v.begin(), v.end(), target) << ' ';
```

### lower_bound, upper_bound
[binary search로 lower_bound 구현](https://github.com/xcelxlorx/algorithm/blob/main/boj/binary_search/%5BG2%5D%2012015%20%EA%B0%80%EC%9E%A5%20%EA%B8%B4%20%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94%20%EB%B6%80%EB%B6%84%20%EC%88%98%EC%97%B4%202.cpp)
```
int idx = lower_bound(x.begin(), x.end(), target) - x.begin(); 		
```

### find, find_if
```
//find
int pos = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();

//find_if
auto it = find_if(numbers.begin(), numbers.end(), [&](const auto &e){ return e == i; });
```

### unique & erase
```
answer.erase(unique(answer.begin(), answer.end()), answer.end());
```

### replace
```
s.replace(i, 3, ""); //i=pos
s.replace(s.find("abc"), 3, "");
```

### count
```
int zero = count(lottos.begin(), lottos.end(), 0);
```

### union, intersection, difference
```
//정렬되어 있어야 함
vector<char> vn(vx.size() + vy.size());
auto iter = set_union(vx.begin(), vx.end(), vy.begin(), vy.end(), vn.begin()); //합집합
auto iter = set_intersection(vx.begin(), vx.end(), vy.begin(), vy.end(), vn.begin()); //교집합
auto iter = set_difference(vx.begin(), vx.end(), vy.begin(), vy.end(), vn.begin()); //차집합
vn.erase(iter, vn.end()); //남는 부분 지우기
```

### inner_product
```
//a * b
int answer = inner_product(A.begin(), A.end(), B.begin(), 0);
```

### gcd
```
//반복문
int temp = a % b;
while(temp > 0){
    a = b;
    b = temp;
    temp = a % b;
}

//재귀
int gcd(int x, int y) {
  return x % y == 0 ? y : gcd(y, x % y);
}
```

### 소숫점 자리 고정
```
cout << fixed;
cout.precision(3);
//ex) 1.123 
```

## function
### replace_all
```
string replace_all(string str, string from, string to){
    int pos = 0;
    while((pos = str.find(from, pos)) != string::npos){
        str.replace(pos, from.length(), to);
        pos += to.length();
    }
    return str;
}
//regex_replace 쓰기
```

### map value sort
```
vector<pair<string, int>> v(m.begin(), m.end());
sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
});
```
