// Solve 2025-02-13

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1145 {

    static int getGCD(int a, int b) {
        if (b == 0) return a;

        return getGCD(b, a % b);
    }

    static int getLCM(int a, int b) {
        return a / getGCD(a, b) * b;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int[] nums = new int[5];

        for (int i = 0; i < 5; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        int ans = nums[0] * nums[1] * nums[2];

        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                int lcm2 = getLCM(nums[i], nums[j]);

                for (int k = j + 1; k < 5; k++) {
                    ans = Math.min(ans, getLCM(lcm2, nums[k]));
                }
            }
        }

        System.out.println(ans);
    }

}
