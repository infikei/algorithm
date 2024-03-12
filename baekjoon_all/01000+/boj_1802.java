// Solve 2024-03-12

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_1802 {

    static String s;

    static boolean recur(int left, int right) {
        if (left == right) {
            return true;
        }

        int mid = (left + right) / 2;
        int i = left;
        int j = right;

        while (i < j) {
            if (s.charAt(i) == s.charAt(j)) {
                return false;
            }

            i++;
            j--;
        }

        if (!recur(left, mid - 1)) {
            return false;
        }

        if (!recur(mid + 1, right)) {
            return false;
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            s = br.readLine();
            sb.append(recur(0, s.length() - 1) ? "YES\n" : "NO\n");
        }

        System.out.print(sb);
        br.close();
    }

}
