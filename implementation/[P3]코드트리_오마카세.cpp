#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    int l, q, c, t, x, n; cin >> l >> q;
    string s, name;
    set<string> names;
    map<string, vector<int>> guest;
    map<string, vector<vector<int>>> sushi;
    map<int, int> sushi_in, sushi_out, guest_in, guest_out;
    map<string, int> exit_time;
    set<int> times;
    map<int, bool> photo;

    while(q--){
        cin >> c;
        if(c == 100){
            //초밥 in
            cin >> t >> x >> name;
            sushi[name].push_back({t, x}); //초밥 생성 시간
            sushi_in[t]++;
        }else if(c == 200){
            //사람 in
            cin >> t >> x >> name >> n;
            guest[name] = {t, x}; //사람 입장 시간
            guest_in[t]++;
            names.insert(name);
        }else{
            cin >> t;
            photo[t] = 1;
        }
        times.insert(t);
    }

    for(string name : names){
        for(auto v : sushi[name]){
            int st = v[0], sx = v[1], gt = guest[name][0], gx = guest[name][1], t = 0;
            if(st < gt){
                //초밥이 사람보다 먼저 들어옴
                int diff = (gt - st) % l;
                sx += sx + diff < l ? diff : diff - l; //gt 전까지 초밥이 벨트에서 이동
                t = gt;
            }else t = st;
            t += gx < sx ? l - sx + gx : gx - sx; 
            sushi_out[t]++; //초밥이 나간 시간
            exit_time[name] = max(exit_time[name], t); //나중에 들어온 초밥이 먼저 나갈 수 있음
            times.insert(t);
        }
    }

    for(auto [key, value] : exit_time) guest_out[value]++; //사람 퇴장

    int scnt = 0, gcnt = 0;
    for(int t : times){
        scnt -= sushi_out[t];
        scnt += sushi_in[t];
        gcnt -= guest_out[t];
        gcnt += guest_in[t];
        if(photo[t]) cout << gcnt << " " << scnt << '\n';
    }

    return 0;
}
