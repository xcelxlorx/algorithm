//조이스틱 커서 최대는 n-1
//A로 인해 커서 횟수가 줄어들 수 있음
//정->역, 역->정으로 가는 방법
//i까지 정방향 탐색 + i 이후로 나오는 A가 아닌 수까지 역방향 탐색
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    int cursor = n - 1;
    
    for(int i = 0; i < n; i++){
        //알파벳 이동
        answer += min(abs('A' - name[i]), abs(name[i] - 'Z') + 1);
        
        //커서 이동
        int next = i + 1;
        while(next < n && name[next] == 'A') next++;
        cursor = min({cursor, i * 2 + n - next, (n - next) * 2 + i});
    }
    
    return answer + cursor;
}
