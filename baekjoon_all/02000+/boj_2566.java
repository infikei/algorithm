// Solve 2024-01-28

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2566 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int maxNum = -1;
        int rowOfMaxNum = -1;
        int colOfMaxNum = -1;

        for (int i = 1; i <= 9; i++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int j = 1; j <= 9; j++) {
                int num = Integer.parseInt(st.nextToken());

                if (num > maxNum) {
                    maxNum = num;
                    rowOfMaxNum = i;
                    colOfMaxNum = j;
                }
            }
        }

        System.out.println(maxNum);
        System.out.println(rowOfMaxNum + " " + colOfMaxNum);
        br.close();
    }
}
