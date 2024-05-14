//oi: 주문 순서, d: 택배 순서
//현재 주문이랑 맞지 않는 택배는 스택에 넣음
import java.util.*;

class Solution {
    public int solution(int[] order) {
        int oi = 0, d = 1, n = order.length;
        Stack<Integer> st = new Stack<>();
        while(oi < n && d <= n){
            if(st.empty() || order[oi] != st.peek()){
                st.push(d); d++; 
            }else{
                oi++; st.pop();
            }
        }
        
        while(!st.empty() && oi < n){
            if(order[oi] == st.peek()){
                oi++; st.pop();
            }else break;
        }
        
        return oi;
    }
}
