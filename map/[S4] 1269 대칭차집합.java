import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]), m = Integer.parseInt(input[1]);
        String[] input1 = br.readLine().split(" ");
        String[] input2 = br.readLine().split(" ");

        Map<String, Integer> mp = new HashMap<>();

        for(int i = 0; i < n; i++) {
            if(mp.get(input1[i]) == null) mp.put(input1[i], 1);
            else mp.put(input1[i], mp.get(input1[i]) + 1);
        }
        for(int i = 0; i < m; i++) {
            if(mp.get(input2[i]) == null) mp.put(input2[i], 1);
            else mp.put(input2[i], mp.get(input2[i]) + 1);
        }
      
        int sum = n + m;
        int dup = 0;
        for(var entry: mp.entrySet()){
            if(entry.getValue() > 1) dup++;
        }

        System.out.println(sum - dup * 2);
    }
}
