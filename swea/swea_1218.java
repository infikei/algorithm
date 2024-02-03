// Solve 2024-02-02

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class swea_1218 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        for (int ti = 1; ti <= 10; ti++) {
            int n = Integer.parseInt(br.readLine());
            char[] ps = br.readLine().toCharArray();
            char[] stack = new char[n];
            int stackSize = 0;
            boolean valid = true;

            for (char p : ps) {
                switch (p) {
                    case '(':
                    case '[':
                    case '{':
                    case '<':
                        stack[stackSize++] = p;
                        break;
                    case ')':
                        if (stackSize == 0 || stack[stackSize - 1] != '(') {
                            valid = false;
                        } else {
                            stackSize--;
                        }
                        break;
                    case ']':
                        if (stackSize == 0 || stack[stackSize - 1] != '[') {
                            valid = false;
                        } else {
                            stackSize--;
                        }
                        break;
                    case '}':
                        if (stackSize == 0 || stack[stackSize - 1] != '{') {
                            valid = false;
                        } else {
                            stackSize--;
                        }
                        break;
                    case '>':
                        if (stackSize == 0 || stack[stackSize - 1] != '<') {
                            valid = false;
                        } else {
                            stackSize--;
                        }
                        break;
                }

                if (!valid) break;
            }

            if (stackSize != 0) {
                valid = false;
            }

            sb.append("#").append(ti).append(" ").append(valid ? 1 : 0).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
