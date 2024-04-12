import java.io.*;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] dist = new int[n];
        for(int i = 0; i < n - 1; i++) dist[i] = Integer.parseInt(input[i]);

        input = br.readLine().split(" ");
        long[] cost = new long[n];
        for(int i = 0; i < n; i++) cost[i] = Integer.parseInt(input[i]);

        long prev = cost[0], sum = 0;
        for(int i = 0; i < n - 1; i++){
           if(cost[i] < prev) prev = cost[i];
           sum += prev * dist[i];
        }
        System.out.println(sum);
    }
}
