import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static int[][] board = new int[9][9];
    static List<List<Integer>> list = new ArrayList<>();
    static boolean fin = false;

    static boolean solve(int x, int y, int n){
        //row, col
        for(int i = 0; i < 9; i++){
            if(board[x][i] == n) return false;
            if(board[i][y] == n) return false;
        }

        //square
        for(int i = x / 3 * 3; i < x / 3 * 3 + 3; i++){
            for(int j = y / 3 * 3; j < y / 3 * 3 + 3; j++){
                if(board[i][j] == n) return false;
            }
        }

        return true;
    }

    static void dfs(int l){
        if(fin) return;
        if(l == list.size()){
            //출력
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    System.out.print(board[i][j] + " ");
                }
                System.out.println();
            }
            fin = true;
            return;
        }

        int x = list.get(l).get(0), y = list.get(l).get(1);
        for(int i = 1; i <= 9; i++){
            if(solve(x, y, i)){
                board[x][y] = i;
                dfs(l + 1);
                board[x][y] = 0;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int i = 0; i < 9; i++){
            String[] input = br.readLine().split(" ");
            for(int j = 0; j < 9; j++){
                board[i][j] = Integer.parseInt(input[j]);
            }
        }

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == 0){
                    list.add(List.of(i, j));
                }
            }
        }

        dfs(0);
    }
}
