import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = br.readLine();
        int n = Integer.parseInt(br.readLine());

        int[][] sum = new int[26][str.length() + 1];
        for(int i = 0; i < 26; i++){
            for(int j = 1; j <= str.length(); j++){
                if(str.charAt(j - 1) - 97 == i) sum[i][j] = sum[i][j - 1] + 1;
                else sum[i][j] = sum[i][j - 1];
            }
        }

        for(int i = 0; i < n; i++){
            String[] input = br.readLine().split(" ");
            int idx = input[0].charAt(0) - 97;
            int start = Integer.parseInt(input[1]);
            int end = Integer.parseInt(input[2]);
            bw.write(sum[idx][end + 1] - sum[idx][start] + "\n");
        }
        bw.flush();
    }
}
