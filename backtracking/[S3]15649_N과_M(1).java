import java.io.*;

public class Main {

    static int n, m;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static boolean[] visited;

    static void back(String s) throws IOException {
        if(s.length() == m) {
            for(int i = 0; i < s.length(); i++){
                bw.write(s.charAt(i) + " ");
            }
            bw.write("\n");
            return;
        }
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                visited[i] = true;
                back(s + i);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]); m = Integer.parseInt(input[1]);
        visited = new boolean[n + 1];
        back("");
        bw.flush();
    }
}
