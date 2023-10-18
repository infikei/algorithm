// Solve 2023-10-18

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class boj_15552 {
    public static void main(String[] args) throws IOException {
        BufferedReader br;
        BufferedWriter bw;
        int testNum;

        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        testNum = Integer.parseInt(br.readLine());

        for (int testIdx = 0; testIdx < testNum; testIdx++) {
            StringTokenizer st;
            int a;
            int b;

            st = new StringTokenizer(br.readLine(), " ");
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            bw.write((a + b) + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}
