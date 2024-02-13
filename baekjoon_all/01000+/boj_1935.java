// Solve 2024-02-12

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_1935 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String postfix = br.readLine();
        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(br.readLine());
        }

        double[] resultStack = new double[100];
        int resultStackSize = 0;

        for (int i = 0; i < postfix.length(); i++) {
            char cur = postfix.charAt(i);

            if (cur >= 'A' && cur <= 'Z') {
                resultStack[resultStackSize++] = nums[cur - 'A'];
            } else if (cur == '+') {
                resultStack[resultStackSize - 2] += resultStack[resultStackSize - 1];
                resultStackSize--;
            } else if (cur == '-') {
                resultStack[resultStackSize - 2] -= resultStack[resultStackSize - 1];
                resultStackSize--;
            } else if (cur == '*') {
                resultStack[resultStackSize - 2] *= resultStack[resultStackSize - 1];
                resultStackSize--;
            } else {
                resultStack[resultStackSize - 2] /= resultStack[resultStackSize - 1];
                resultStackSize--;
            }
        }

        System.out.printf("%.2f%n", resultStack[0]);
        br.close();
    }

}
