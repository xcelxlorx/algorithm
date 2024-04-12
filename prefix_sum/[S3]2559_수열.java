import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]), k = Integer.parseInt(input[1]);

        String[] arr = br.readLine().split(" ");
        int[] sum = new int[n + 1];
        for(int i = 1; i <= n; i++){
            sum[i] = sum[i - 1] + Integer.parseInt(arr[i - 1]);
        }

        int answer = -987654321;
        for(int i = k; i <= n; i++){
            answer = Math.max(answer, sum[i] - sum[i - k]);
        }
        System.out.println(answer);
    }
}
