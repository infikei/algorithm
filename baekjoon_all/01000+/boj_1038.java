// Solve 2024-06-16

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class boj_1038 {

    static ArrayList<Long> nums = new ArrayList<Long>();

    static void recur(long x) {
        nums.add(x);

        for (long i = x % 10 - 1; i >= 0; i--) {
            recur(x * 10 + i);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int x = 0; x < 10; x++) {
            recur(x);
        }

        Collections.sort(nums);

        if (n >= nums.size()) {
            System.out.println(-1);
        } else {
            System.out.println(nums.get(n));
        }

        br.close();
    }

}
