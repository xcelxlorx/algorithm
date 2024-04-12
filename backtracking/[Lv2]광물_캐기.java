import java.util.*;

class Solution {

    int answer = 987654321;
    
    int calculate(int pick, int mi, String[] minerals, int last){
        int fatigue = 0;
        for(int j = mi; j < last; j++){
            String cur = minerals[j];
            if(cur.equals("diamond") && pick == 2) fatigue += 25;
            else if(cur.equals("diamond") && pick == 1) fatigue += 5;
            else if(cur.equals("iron") && pick == 2) fatigue += 5;
            else fatigue++;
        }
        return fatigue;
    }
    
    void back(String[] minerals, int[] picks, int mi, int fatigue){  
        if(mi >= minerals.length || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0)){
            answer = Math.min(fatigue, answer);
            return;
        }
        
        for(int i = 0; i < 3; i++){
            if(picks[i] > 0){
                picks[i]--;   
                int last = mi + 5 > minerals.length ? minerals.length : mi + 5;
                int cur = calculate(i, mi, minerals, last);
                back(minerals, picks, last, fatigue + cur);
                picks[i]++;
            }         
        }
    }
    
    public int solution(int[] picks, String[] minerals) {
        back(minerals, picks, 0, 0);
        return answer;
    }
}
