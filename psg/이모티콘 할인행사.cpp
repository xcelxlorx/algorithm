#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int plus_user = 0;
int sales = 0;
vector<int> discounts = {40, 30, 20, 10};

void calculate(vector<vector<int>> &users, vector<int> &emoticons, vector<int> &permutation){
    int current_plus_user = 0;
    int current_sales = 0;
    
    for(auto user : users){
        int user_sales = 0;
        for(int i = 0; i < permutation.size(); i++){
            int emoticon_discount = permutation[i];
            if(emoticon_discount >= user[0]){
                user_sales += emoticons[i] * (100 - emoticon_discount) / 100;
            }
        }
        
        if(user_sales >= user[1]){
            current_plus_user++;
        }else{
            current_sales += user_sales;
        }
    }
    
    if(plus_user <= current_plus_user){
        if(plus_user == current_plus_user){
            if(sales < current_sales){
                sales = current_sales;
            }
        }else{
            plus_user=  current_plus_user;
            sales = current_sales;
        }
    }
}

void repeated_permutation(vector<vector<int>> &users, vector<int> &emoticons,
                          vector<int> &result, int cnt, int max_cnt){
    if(cnt == max_cnt){
        calculate(users, emoticons, result);
        return;
    }
    for(int i = 0; i < 4; i++){
        result.push_back(discounts[i]);
        repeated_permutation(users, emoticons, result, cnt + 1, max_cnt);
        result.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> result;
    repeated_permutation(users, emoticons, result, 0, emoticons.size());
    
    return {plus_user, sales};
}
