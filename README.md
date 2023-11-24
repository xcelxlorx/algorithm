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
