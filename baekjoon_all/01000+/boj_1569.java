// Solve 2024-02-02

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1569 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        int[] x = new int[n];
        int[] y = new int[n];

        int minX = 1001;
        int maxX = -1001;
        int minY = 1001;
        int maxY = -1001;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            x[i] = Integer.parseInt(st.nextToken());
            y[i] = Integer.parseInt(st.nextToken());

            minX = Math.min(minX, x[i]);
            maxX = Math.max(maxX, x[i]);
            minY = Math.min(minY, y[i]);
            maxY = Math.max(maxY, y[i]);
        }

        int lenX = maxX - minX;
        int lenY = maxY - minY;
        int lenSquare = Math.max(lenX, lenY);

        if (lenX > lenY) {
            int y1 = maxY - lenSquare;
            int y2 = maxY;
            boolean flagPossible = false;

            while (y1 <= minY) {
                boolean flag = true;

                for (int i = 0; i < n; i++) {
                    if (x[i] != minX && x[i] != maxX && y[i] != y1 && y[i] != y2) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    flagPossible = true;
                    break;
                }

                y1++;
                y2++;
            }

            if (!flagPossible) lenSquare = -1;
        } else if (lenX < lenY) {
            int x1 = maxX - lenSquare;
            int x2 = maxX;
            boolean flagPossible = false;

            while (x1 <= minX) {
                boolean flag = true;

                for (int i = 0; i < n; i++) {
                    if (x[i] != x1 && x[i] != x2 && y[i] != minY && y[i] != maxY) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    flagPossible = true;
                    break;
                }

                x1++;
                x2++;
            }

            if (!flagPossible) lenSquare = -1;
        } else {
            for (int i = 0; i < n; i++) {
                if (x[i] != minX && x[i] != maxX && y[i] != minY && y[i] != maxY) {
                    lenSquare = -1;
                    break;
                }
            }
        }

        System.out.println(lenSquare);
        br.close();
    }

}
