import java.io.*;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out), 1 << 25);
    static int cnt = 0;

    static void move(int n, int from, int to, int other) throws IOException {
        cnt++;
        if(n == 1){
            bw.write(from + " " + to + "\n");
            return;
        }
        move(n - 1, from, other, to);
        bw.write(from + " " + to + "\n");
        move(n - 1, other, to, from);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        move(n, 1, 3, 2);
        System.out.println(cnt);
        bw.flush();
    }
}
