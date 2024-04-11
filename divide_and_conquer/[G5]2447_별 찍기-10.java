import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static char[][] arr;

    static void divide(int l, int x, int y){
        if(l == 1){
            arr[x][y] = '*';
            return;
        }

        int nx = x, ny = y;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i == 1 && j == 1) {
                    ny += l/3; continue;
                }
                divide(l/3, nx, ny);
                ny += l/3;
            }
            nx += l/3; ny = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        arr = new char[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr[i][j] = ' ';
            }
        }
        divide(n, 0, 0);
        for(int i = 0; i < n; i++){
            System.out.println(arr[i]);
        }
    }
}
