### 입출력: BufferedReader, BufferedWriter
```
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String name = br.readLine();
        int year = Integer.parseInt(br.readLine());

        //write
        for(int i = 0; i < t; i++) {
            String[] arr = br.readLine().split(" ");
            bw.write(Integer.parseInt(arr[0]) + Integer.parseInt(arr[1]) + "\n");
        }
        bw.flush();

        //계속 입력
        String s;
        while((s = br.readLine()) != null){
            System.out.println(s);
        }
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

### 비교: equals
```
//값 비교 - equals
//주소값 비교 - ==
s.equals("dz=")
```

### 문자열: substring
```
s.substring(시작 인덱스, 끝 인덱스) //[begin, end)
```

### Map
```
Map<String, Double> m = new HashMap<>();
m.put("A+", 4.5);
m.get(cls[2]);
```

### 스택
```
import java.util.Stack;
Stack<String> st = new Stack<>();
st.peek(); //stack top
```
