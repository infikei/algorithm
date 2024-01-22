// Solve 2024-01-21

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_10773 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());
        int[] stack = new int[k + 1];
        stack[0] = 0;
        int stackSize = 1;

        while (k-- > 0) {
            int x = Integer.parseInt(br.readLine());

            if (x == 0) {
                stackSize--;
            } else {
                stack[stackSize] = stack[stackSize - 1] + x;
                stackSize++;
            }
        }

        System.out.println(stack[stackSize - 1]);
        br.close();
    }
}
