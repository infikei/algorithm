// Solve 2024-04-14

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_6996 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            String s1 = st.nextToken();
            String s2 = st.nextToken();
            int[] alphaCnt = new int[26];

            for (int j = 0; j < s1.length(); j++) {
                alphaCnt[s1.charAt(j) - 'a']++;
            }

            for (int j = 0; j < s2.length(); j++) {
                alphaCnt[s2.charAt(j) - 'a']--;
            }

            boolean valid = true;

            for (int j = 0; j < 26; j++) {
                if (alphaCnt[j] != 0) {
                    valid = false;
                    break;
                }
            }

            sb.append(s1).append(" & ").append(s2).append(" are ").append(valid ? "anagrams.\n" : "NOT anagrams.\n");
        }

        System.out.println(sb);
        br.close();
    }

}
