// Solve 2024-02-12

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_1918 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String infix = br.readLine();
        StringBuilder postfix = new StringBuilder();
        char[] operatorStack = new char[100];
        int operatorStackSize = 0;

        for (int i = 0; i < infix.length(); i++) {
            char cur = infix.charAt(i);

            if (cur == '(') {
                operatorStack[operatorStackSize++] = cur;
            } else if (cur == ')') {
                while (operatorStack[operatorStackSize - 1] != '(') {
                    postfix.append(operatorStack[--operatorStackSize]);
                }

                operatorStackSize--;
            } else if (cur == '+' || cur == '-') {
                while (operatorStackSize >= 1 && operatorStack[operatorStackSize - 1] != '(') {
                    postfix.append(operatorStack[--operatorStackSize]);
                }

                operatorStack[operatorStackSize++] = cur;
            } else if (cur == '*' || cur == '/') {
                while (operatorStackSize >= 1 && operatorStack[operatorStackSize - 1] != '('
                        && operatorStack[operatorStackSize - 1] != '+' && operatorStack[operatorStackSize - 1] != '-') {
                    postfix.append(operatorStack[--operatorStackSize]);
                }

                operatorStack[operatorStackSize++] = cur;
            } else {
                postfix.append(cur);
            }
        }

        while (operatorStackSize >= 1) {
            postfix.append(operatorStack[--operatorStackSize]);
        }

        System.out.println(postfix);
        br.close();
    }

}
