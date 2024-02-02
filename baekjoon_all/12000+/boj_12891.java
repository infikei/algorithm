// Solve 2024-02-01

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_12891 {

    static char[] acgt = { 'A', 'C', 'G', 'T' };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int s = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        String dna = br.readLine();
        st = new StringTokenizer(br.readLine(), " ");
        int[] minCnt = new int[26];

        for (int i = 0; i < 4; i++) {
            minCnt[acgt[i] - 'A'] = Integer.parseInt(st.nextToken());
        }

        int begin = 0;
        int end = 0;
        int[] curCnt = new int[26];

        while (end < p) {
            curCnt[dna.charAt(end) - 'A']++;
            end++;
        }

        int ans = 0;

        if (isInRange(minCnt, curCnt)) ans++;

        while (end < s) {
            curCnt[dna.charAt(begin) - 'A']--;
            curCnt[dna.charAt(end) - 'A']++;
            begin++;
            end++;

            if (isInRange(minCnt, curCnt)) ans++;
        }

        System.out.println(ans);
        br.close();
    }

    static boolean isInRange(int[] minCnt, int[] curCnt) {
        for (char x : acgt) {
            if (curCnt[x - 'A'] < minCnt[x - 'A']) {
                return false;
            }
        }

        return true;
    }

}
