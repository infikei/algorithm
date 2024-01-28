// Solve 2023-11-17
// Update 2024-01-28

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_2562 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int maxNum = 0;
        int idxOfMaxNum = 0;

        for (int i = 1; i <= 9; i++) {
            int num = Integer.parseInt(br.readLine());

            if (num > maxNum) {
                maxNum = num;
                idxOfMaxNum = i;
            }
        }

        System.out.println(maxNum);
        System.out.println(idxOfMaxNum);
        br.close();
    }

}
