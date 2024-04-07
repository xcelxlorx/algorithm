## 입력
```
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String name = br.readLine();
        int year = Integer.parseInt(br.readLine());

        //a b c와 같이 공백으로 들어올 때
        String[] input = br.readLine().split(" ");
        int a = Integer.parseInt(input[0]);
    }
}

```

