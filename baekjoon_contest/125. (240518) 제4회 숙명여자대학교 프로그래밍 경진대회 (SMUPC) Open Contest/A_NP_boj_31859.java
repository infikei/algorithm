// Solve 2024-05-19

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A_NP_boj_31859 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        String s = st.nextToken();
        int[] alphaCount = new int[26];
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (alphaCount[s.charAt(i) - 'a'] == 0) {
                alphaCount[s.charAt(i) - 'a']++;
                sb.append(s.charAt(i));
            }
        }

        StringBuilder sb2 = new StringBuilder();
        sb2.append(n + 1906).append(sb).append(s.length() - sb.length() + 4).append("_cpums").reverse();
        System.out.println(sb2);
        br.close();
    }

}
