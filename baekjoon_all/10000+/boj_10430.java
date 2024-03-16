// Solve 2023-11-17
// Update 2024-03-16

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_10430 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        sb.append((a + b) % c).append("\n");
        sb.append((a % c + b % c) % c).append("\n");
        sb.append(a * b % c).append("\n");
        sb.append(((a % c) * (b % c)) % c).append("\n");

        System.out.print(sb);
        br.close();
    }

}
