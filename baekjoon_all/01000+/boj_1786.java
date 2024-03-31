// Solve 2024-03-29

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_1786 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String t = br.readLine(); // 본문
        String p = br.readLine(); // 패턴

        int[] pi = new int[p.length()]; // 부분일치 테이블 배열
        int i = 1; // 본문 포인터
        int j = 0; // 패턴 포인터

        while (i < p.length()) {
            if (p.charAt(i) == p.charAt(j)) {
                i++;
                j++;
                pi[i - 1] = j;
            } else {
                if (j > 0) {
                    j = pi[j - 1];
                } else {
                    i++;
                }
            }
        }

        i = 0; // 본문 포인터
        j = 0; // 패턴 포인터
        int cnt = 0; // 등장 횟수

        while (i < t.length()) {
            if (t.charAt(i) == p.charAt(j)) {
                i++;
                j++;

                if (j == p.length()) {
                    cnt++;
                    sb.append(i - p.length() + 1).append(" ");
                    j = pi[j - 1];
                }
            } else {
                if (j > 0) {
                    j = pi[j - 1];
                } else {
                    i++;
                }
            }
        }

        System.out.println(cnt);
        System.out.println(sb);
        br.close();
    }

}
