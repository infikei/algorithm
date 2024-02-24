// Solve 2024-02-23

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_17281_nextpermutation {

    static int n;
    static int[][] results;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        results = new int[n][9];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int j = 0; j < 9; j++) {
                results[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[] perm = { 1, 2, 3, 4, 5, 6, 7, 8 };
        int[] orderToPlayer = new int[9];
        int maxScore = 0;

        do {
            for (int i = 0; i < 3; i++) {
                orderToPlayer[i] = perm[i];
            }

            for (int i = 4; i < 9; i++) {
                orderToPlayer[i] = perm[i - 1];
            }

            int curScore = playBaseball(orderToPlayer);

            if (curScore > maxScore) {
                maxScore = curScore;
            }
        } while (nextPermutation(perm));

        System.out.println(maxScore);
        br.close();
    }

    static int playBaseball(int[] orderToPlayer) {
        int curScore = 0;
        int curInning = 0;
        int curOrder = 0;
        int[] bases = new int[5];

        while (curInning < n) {
            for (int curBase = 0; curBase < 5; curBase++) {
                bases[curBase] = 0;
            }

            int curOuts = 0;

            while (curOuts < 3) {
                int curResult = results[curInning][orderToPlayer[curOrder]];

                if (curResult == 0) {
                    curOuts++;
                } else {
                    bases[0] = 1;

                    for (int curBase = 3; curBase >= 0; curBase--) {
                        if (bases[curBase] == 1) {
                            bases[curBase] = 0;
                            bases[Math.min(curBase + curResult, 4)]++;
                        }
                    }

                    curScore += bases[4];
                    bases[4] = 0;
                }

                if (++curOrder == 9) {
                    curOrder = 0;
                }
            }

            curInning++;
        }

        return curScore;
    }

    static boolean nextPermutation(int[] p) {
        int n = p.length;
        int i = n - 1;

        while (i >= 1 && p[i - 1] >= p[i]) {
            i--;
        }

        if (i == 0) return false;

        int j = n - 1;

        while (p[i - 1] >= p[j]) {
            j--;
        }

        swap(p, i - 1, j);
        j = n - 1;

        while (i < j) {
            swap(p, i++, j--);
        }

        return true;
    }

    static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

}
