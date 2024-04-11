import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static char[] line;

    static void divide(int l, int b, int e){
        if(l == 0 || b >= e) return;
        int start = b + l, end = e - l;
        for(int i = start; i <= end; i++) line[i] = ' ';
        divide(l/3, b, start - 1);
        divide(l/3, end + 1, e);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s;
        while((s = br.readLine()) != null){
            int n = Integer.parseInt(s);
            int cnt = 1;
            for(int i = 0; i < n; i++) cnt *= 3;
            
            line = new char[cnt];
            for(int i = 0; i < cnt; i++) line[i] = '-';

            divide(cnt / 3, 0, cnt - 1);
            
            System.out.println(line);
        }
    }
}
