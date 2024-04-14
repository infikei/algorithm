// Solve 2024-04-14

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;

public class boj_2295 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        ArrayList<Integer> sumList = new ArrayList<Integer>();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                sumList.add(arr[i] + arr[j]);
            }
        }

        HashMap<Integer, Integer> diffHashMap = new HashMap<Integer, Integer>();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int diff = Math.abs(arr[i] - arr[j]);

                if (diffHashMap.get(diff) == null) {
                    diffHashMap.put(diff, Math.max(arr[i], arr[j]));
                } else {
                    diffHashMap.put(diff, Math.max(diffHashMap.get(diff), Math.max(arr[i], arr[j])));
                }
            }
        }

        int ans = -1;

        for (int i = sumList.size() - 1; i >= 0; i--) {
            if (diffHashMap.get(sumList.get(i)) != null) {
                ans = Math.max(ans, diffHashMap.get(sumList.get(i)));
            }
        }

        System.out.println(ans);
        br.close();
    }

}
