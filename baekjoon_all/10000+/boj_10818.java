// Solve 2023-11-17

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class boj_10818 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        br.close();
        int answerMininum = 1_000_000;
        int answerMaximum = -1_000_000;

        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(st.nextToken());

            if (x < answerMininum) {
                answerMininum = x;
            }

            if (x > answerMaximum) {
                answerMaximum = x;
            }
        }

        bw.write(answerMininum + " " + answerMaximum + "\n");
        bw.flush();
        bw.close();
    }
}
