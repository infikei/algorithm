// Solve 2023-11-17
// Update 2024-03-11

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_25314 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n4 = Integer.parseInt(br.readLine()) / 4;

        for (int i = 0; i < n4; i++) {
            sb.append("long ");
        }

        sb.append("int");
        System.out.println(sb);
        br.close();
    }

}
