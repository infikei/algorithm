// Solve 2024-09-05

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_31281 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        long[] numbers = new long[3];

        for (int i = 0; i < 3; i++) {
            numbers[i] = Long.parseLong(st.nextToken());
        }

        Arrays.sort(numbers);
        System.out.println(numbers[1]);
        br.close();
    }

}
