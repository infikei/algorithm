// Solve 2024-02-21

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_1759 {

    static char[] vowels = { 'a', 'e', 'i', 'o', 'u' };
    static StringBuilder sb = new StringBuilder();
    static int l, c;
    static char[] chars;
    static boolean[] charsCheckedVowels;
    static char[] selected;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        l = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        chars = new char[c];
        charsCheckedVowels = new boolean[c];
        selected = new char[l];

        for (int i = 0; i < c; i++) {
            chars[i] = st.nextToken().charAt(0);
        }

        Arrays.sort(chars);

        for (int i = 0; i < c; i++) {
            for (char v : vowels) {
                if (chars[i] == v) {
                    charsCheckedVowels[i] = true;
                    break;
                }
            }
        }

        dfs(0, 0, 1, 2);
        System.out.print(sb);
        br.close();
    }

    static void dfs(int depth, int beginIdx, int vowelNeed, int notVowelNeed) {
        if (depth == l) {
            if (vowelNeed <= 0 && notVowelNeed <= 0) {
                for (char ch : selected) {
                    sb.append(ch);
                }

                sb.append("\n");
            }

            return;
        }

        for (int i = beginIdx; i < c; i++) {
            selected[depth] = chars[i];

            if (charsCheckedVowels[i]) {
                dfs(depth + 1, i + 1, vowelNeed - 1, notVowelNeed);
            } else {
                dfs(depth + 1, i + 1, vowelNeed, notVowelNeed - 1);
            }
        }
    }

}
