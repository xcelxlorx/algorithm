import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static int n = 0;
    static int[] arr;
    static List<Integer> order = new ArrayList<>();

    static void merge(List<Integer> list, int left, int mid, int right){
        int i = left, j = mid + 1, k = 1;

        while(i <= mid && j <= right){
            if(list.get(i) <= list.get(j)) arr[k++] = list.get(i++);
            else arr[k++] = list.get(j++);
        }

        while(i <= mid) arr[k++] = list.get(i++);
        while(j <= right) arr[k++] = list.get(j++);
        i = left; k = 1;
        while(i <= right) {
            list.set(i++, arr[k++]);
            order.add(arr[k - 1]);
        }
    }

    static void merge_sort(List<Integer> list, int left, int right){
        if(left < right){
            int mid = (left + right) / 2;
            merge_sort(list, left, mid);
            merge_sort(list, mid + 1, right);
            merge(list, left, mid, right);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        String[] ele = br.readLine().split(" ");

        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < n; i++){
            list.add(Integer.parseInt(ele[i]));
        }

        arr = new int[n + 1];
        merge_sort(list, 0, n - 1);

        if(k > order.size()) System.out.println(-1);
        else System.out.println(order.get(k - 1));
    }
}
