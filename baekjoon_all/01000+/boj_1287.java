// Solve 2024-02-12

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class boj_1287 {

    static BigInteger[] numberStack = new BigInteger[1000];
    static int numberStackSize = 0;
    static char[] operatorStack = new char[1000];
    static int operatorStackSize = 0;

    static BigInteger calculate(BigInteger a, BigInteger b, char op) {
        if (op == '+') {
            return a.add(b);
        } else if (op == '-') {
            return a.subtract(b);
        } else if (op == '*') {
            return a.multiply(b);
        } else if (op == '/' && !b.equals(new BigInteger("0"))) {
            return a.divide(b);
        }

        return null;
    }

    static BigInteger calculateLastTwoIntegers() {
        return calculate(numberStack[numberStackSize - 2], numberStack[numberStackSize - 1], operatorStack[operatorStackSize - 1]);
    }

    static boolean isFourBasicOperations(char op) {
        return op == '+' || op == '-' || op == '*' || op == '/';
    }

    static boolean isMulOrDiv(char op) {
        return op == '*' || op == '/';
    }

    static boolean checkFormat(String expression, int idx) {
        if (expression.charAt(idx) == '(') {
            return idx + 1 < expression.length() && expression.charAt(idx + 1) != ')'
                    && expression.charAt(idx + 1) != '+' && expression.charAt(idx + 1) != '-'
                    && expression.charAt(idx + 1) != '*' && expression.charAt(idx + 1) != '/';
        } else if (expression.charAt(idx) == ')') {
            return idx - 1 >= 0 && expression.charAt(idx - 1) != '+' && expression.charAt(idx - 1) != '-'
                    && expression.charAt(idx - 1) != '*' && expression.charAt(idx - 1) != '/';
        }

        return true;
    }

    static boolean operate(char op) {
        if (op == '(') {
            operatorStack[operatorStackSize++] = '(';
        } else if (op == ')') {
            while (operatorStackSize >= 1 && isFourBasicOperations(operatorStack[operatorStackSize - 1])) {
                if (numberStackSize < 2) return false;

                numberStack[numberStackSize - 2] = calculateLastTwoIntegers();
                numberStackSize--;
                operatorStackSize--;

                if (numberStack[numberStackSize - 1] == null) return false;
            }

            if (--operatorStackSize < 0) return false;
        } else if (op == '+' || op == '-') {
            while (operatorStackSize >= 1 && isFourBasicOperations(operatorStack[operatorStackSize - 1])) {
                if (numberStackSize < 2) return false;

                numberStack[numberStackSize - 2] = calculateLastTwoIntegers();
                numberStackSize--;
                operatorStackSize--;

                if (numberStack[numberStackSize - 1] == null) return false;
            }

            operatorStack[operatorStackSize++] = op;
        } else if (op == '*' || op == '/') {
            while (operatorStackSize >= 1 && isMulOrDiv(operatorStack[operatorStackSize - 1])) {
                if (numberStackSize < 2) return false;

                numberStack[numberStackSize - 2] = calculateLastTwoIntegers();
                numberStackSize--;
                operatorStackSize--;

                if (numberStack[numberStackSize - 1] == null) return false;
            }

            operatorStack[operatorStackSize++] = op;
        }

        return true;
    }

    static boolean operateFinally() {
        while (operatorStackSize >= 1) {
            if (operatorStack[operatorStackSize - 1] == '(' || numberStackSize < 2) return false;

            numberStack[numberStackSize - 2] = calculateLastTwoIntegers();
            numberStackSize--;
            operatorStackSize--;

            if (numberStack[numberStackSize - 1] == null) return false;
        }

        if (numberStackSize != 1 || operatorStackSize != 0) return false;

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String expression = br.readLine();
        boolean validExpression = true;
        StringBuilder newNumber = new StringBuilder();

        for (int i = 0; i < expression.length(); i++) {
            char digitOrOperator = expression.charAt(i);

            if (digitOrOperator >= '0' && digitOrOperator <= '9') {
                newNumber.append(digitOrOperator);
            } else {
                if (newNumber.length() > 0) {
                    numberStack[numberStackSize++] = new BigInteger(newNumber.toString());
                    newNumber = new StringBuilder();
                }

                if (!checkFormat(expression, i)) {
                    validExpression = false;
                    break;
                }

                if (!operate(digitOrOperator)) {
                    validExpression = false;
                    break;
                }
            }
        }

        if (validExpression) {
            if (newNumber.length() > 0) {
                numberStack[numberStackSize++] = new BigInteger(newNumber.toString());
                newNumber = new StringBuilder();
            }

            if (!operateFinally()) {
                validExpression = false;
            }
        }

        if (validExpression) {
            System.out.println(numberStack[0]);
        } else {
            System.out.println("ROCK");
        }

        br.close();
    }

}
