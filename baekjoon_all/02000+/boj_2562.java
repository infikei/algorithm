// Solve 2023-11-17

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class boj_2562 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int maxValue = 0;
        int maxIndex = 0;

        for (int i = 1; i <= 9; i++) {
            int value = Integer.parseInt(br.readLine());

            if (value > maxValue) {
                maxValue = value;
                maxIndex = i;
            }
        }

        br.close();
        bw.write(maxValue + "\n" + maxIndex + "\n");
        bw.flush();
        bw.close();
    }
}
