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

### 문자열: substring, StringBuilder
```
//substring
s.substring(시작 인덱스, 끝 인덱스) //[begin, end)

//string builder(+보다 빠름)
StringBuilder sb = new StringBuilder();
sb.append(q.peek()).append(" ");
```

### Map
```
Map<String, Double> m = new HashMap<>();
m.put("A+", 4.5);
m.get(cls[2]);

//map for
for(var entry: mp.entrySet()){
    if(entry.getValue() > 1) dup++;
}

//map은 null 체크해야 함
for(int i = 0; i < m; i++) {
    if(mp.get(input2[i]) == null) mp.put(input2[i], 1);
    else mp.put(input2[i], mp.get(input2[i]) + 1);
}
```

### Stack
```
import java.util.Stack;
Stack<String> st = new Stack<>();
st.peek(); //stack top
```

### Queue
```
import java.util.*;
Queue<String> q = new LinkedList<>();
q.offer(b[i]);
```

### Deque
```
import java.util.ArrayDeque;
ArrayDeque<Integer> dq = new ArrayDeque<>();
dq.offerLast(); //뒤에 push
dq.peekFirst(); //front
dq.peekLast(); //back
dq.pollFirst(); //앞에 pop
```

### Set
```
import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

Set<String> s = new HashSet<>();
Set<String> s = new TreeSet<>(); //사전순 정렬
s.add(str);
if(s.contains(str)) cnt++; //set에 있는지 확인
s.remove(str[0]); //원소가 없으면 무시됨
s.clear();

//[set 내림차순 출력] descendingSet()
for(String e : ((TreeSet<String>)s).descendingSet()) {
    System.out.println(e);
}

//[set 복사하기]
Set<String> cp = b; //얕은 복사 -> x
cp.addAll(b); // o

```

### sort
```
//list 정렬
import java.util.Collections;
Collections.sort(list);
```
