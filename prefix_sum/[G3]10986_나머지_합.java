//모듈러 연산
//(sum[i] - sum[j]) % m -> sum[i] % m = sum[j] % m : j + 1 ~ i
//0 ~ i도 고려해야 함
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]), m = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        long[] nums = new long[n + 1];
        long[] cnt = new long[m];
        for(int i = 1; i <= n; i++) nums[i] = Integer.parseInt(input[i - 1]);

        for(int i = 1; i <= n; i++) {
            nums[i] += nums[i - 1];
            cnt[(int)(nums[i] % m)]++;
        }

        long sum = 0;
        for(int i = 0; i < m; i++){
            sum += cnt[i] * (cnt[i] - 1) / 2; //n개 * 선택한 이후 n-1개 / 2 (중복)
        }
        System.out.println(sum + cnt[0]);
    }
}
