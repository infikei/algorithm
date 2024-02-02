// Solve 2024-02-01

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_27535 {

    static class Choco implements Comparable<Choco> {
        char type;
        int num;

        Choco(char type, int num) {
            this.type = type;
            this.num = num;
        }

        @Override
        public int compareTo(Choco c) {
            if (num != c.num) return c.num - num;

            return type - c.type;
        }
    }

    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        char[] chocoType = { 'H', 'T', 'C', 'K', 'G' };
        Choco[] chocos = new Choco[5];
        int chocoSum = 0;
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        for (int i = 0; i < 5; i++) {
            int x = Integer.parseInt(st.nextToken());
            chocos[i] = new Choco(chocoType[i], x);
            chocoSum += x;
        }

        int n = Integer.parseInt(br.readLine());
        int base = getBase(chocoSum);

        for (int ni = 0; ni < n; ni++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int i = 0; i < 5; i++) {
                int x = Integer.parseInt(st.nextToken());
                chocos[i].num -= x;
                chocoSum -= x;
            }

            printNumWithBase(chocoSum, base);
            printSortedChocos(chocos, chocoSum);
            base = getBase(chocoSum);
        }

        System.out.print(sb);
        br.close();
    }

    static int getBase(int chocoSum) {
        int base = chocoSum % 10;

        return base <= 1 ? 10 : base;
    }

    static void printNumWithBase(int num, int base) {
        if (num == 0) {
            sb.append("07H\n");
            return;
        }

        int[] digits = new int[23];
        int digitsSize = 0;

        while (num > 0) {
            digits[digitsSize++] = num % base;
            num /= base;
        }

        while (--digitsSize >= 0) {
            sb.append(digits[digitsSize]);
        }

        sb.append("7H\n");
    }

    static void printSortedChocos(Choco[] chocos, int chocoSum) {
        if (chocoSum == 0) {
            sb.append("NULL\n");
            return;
        }

        Choco[] sortedChocos = new Choco[5];

        for (int i = 0; i < 5; i++) {
            sortedChocos[i] = chocos[i];
        }

        Arrays.sort(sortedChocos);

        for (Choco c : sortedChocos) {
            if (c.num == 0) break;

            sb.append(c.type);
        }

        sb.append("\n");
    }

}
