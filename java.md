### 입출력: BufferedReader, BufferedWriter
```
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String name = br.readLine();
        int year = Integer.parseInt(br.readLine());

        for(int i = 0; i < t; i++) {
            String[] arr = br.readLine().split(" ");
            bw.write(Integer.parseInt(arr[0]) + Integer.parseInt(arr[1]) + "\n");
        }
        bw.flush();
    }
}
```

### 문자 -> 숫자: getNumericValue()
```
String b = br.readLine();
int n1 = Character.getNumericValue(b.charAt(2));
```

### long
```
//long은 10^18까지 가능
long n1 = Long.parseLong(input[0]);
```

### Math
```
System.out.println(Math.max(Math.max(n1, n2), n3) * 100);
```
