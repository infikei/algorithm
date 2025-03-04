// Solve 2024-02-02
// Update 2025-03-04

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1569 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
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
        int squareLength = Math.max(lenX, lenY);

        if (lenX > lenY) {
            int y1 = maxY - squareLength;
            int y2 = maxY;
            boolean possible = false;

            while (y1 <= minY) {
                boolean allPointsOnSquare = true;

                for (int i = 0; i < n; i++) {
                    if (x[i] != minX && x[i] != maxX && y[i] != y1 && y[i] != y2) {
                        allPointsOnSquare = false;
                        break;
                    }
                }

                if (allPointsOnSquare) {
                    possible = true;
                    break;
                }

                y1++;
                y2++;
            }

            if (!possible) {
                squareLength = -1;
            }
        } else if (lenX < lenY) {
            int x1 = maxX - squareLength;
            int x2 = maxX;
            boolean possible = false;

            while (x1 <= minX) {
                boolean allPointsOnSquare = true;

                for (int i = 0; i < n; i++) {
                    if (x[i] != x1 && x[i] != x2 && y[i] != minY && y[i] != maxY) {
                        allPointsOnSquare = false;
                        break;
                    }
                }

                if (allPointsOnSquare) {
                    possible = true;
                    break;
                }

                x1++;
                x2++;
            }

            if (!possible) {
                squareLength = -1;
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (x[i] != minX && x[i] != maxX && y[i] != minY && y[i] != maxY) {
                    squareLength = -1;
                    break;
                }
            }
        }

        System.out.println(squareLength);
    }

}
