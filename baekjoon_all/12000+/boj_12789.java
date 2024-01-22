// Solve 2024-01-21

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_12789 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int[] stack = new int[n];
        int stackSize = n;

        for (int i = n - 1; i >= 0; i--) {
            stack[i] = Integer.parseInt(st.nextToken());
        }

        int[] anotherStack = new int[n];
        int anotherStackSize = 0;
        boolean isNice = true;

        for (int i = 1; i <= n; i++) {
            if (anotherStackSize > 0 && anotherStack[anotherStackSize - 1] == i) {
                anotherStackSize--;
            } else {
                while (stackSize > 0 && stack[stackSize - 1] != i) {
                    anotherStack[anotherStackSize++] = stack[--stackSize];
                }

                if (stackSize > 0 && stack[stackSize - 1] == i) {
                    stackSize--;
                } else {
                    isNice = false;
                    break;
                }
            }
        }

        System.out.println(isNice ? "Nice\n" : "Sad\n");
        br.close();
    }
}
