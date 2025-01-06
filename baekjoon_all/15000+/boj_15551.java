// Solve 2025-01-02

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_15551 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();

        for (int i = 2; i < n; i++) {
            sb.append('1');
        }

        StringBuilder sb2 = new StringBuilder();
        sb2.append(sb.toString());

        sb.append("1P");
        sb2.append("21");

        System.out.println(sb.toString());
        System.out.println(sb2.toString());

        br.close();
    }

}
