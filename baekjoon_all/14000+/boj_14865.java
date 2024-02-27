// Solve 2024-02-26

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class boj_14865 {

    static class Par implements Comparable<Par> {
        char par;
        int x;

        public Par(char par, int x) {
            this.par = par;
            this.x = x;
        }

        @Override
        public int compareTo(Par o) {
            return x < o.x ? -1 : 1;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int[][] points = new int[n][2];
        int minX = Integer.MAX_VALUE;
        int minY = Integer.MAX_VALUE;
        int minIdx = 0;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            points[i][0] = Integer.parseInt(st.nextToken());
            points[i][1] = Integer.parseInt(st.nextToken());

            // 가장 왼쪽 아래 점 찾기
            if (points[i][0] < minX || (points[i][0] == minX && points[i][1] < minY)) {
                minX = points[i][0];
                minY = points[i][1];
                minIdx = i;
            }
        }

        ArrayList<Par> pars = new ArrayList<Par>();
        int[] xTmpArr = new int[2];
        int xTmpArrIdx = 0;
        int px = minX;
        int py = minY;

        for (int i = 1, j = minIdx + 1; i < n; i++, j++) {
            if (j >= n) {
                j -= n;
            }

            int x = points[j][0];
            int y = points[j][1];

            if (px == x) {
                if ((py < 0 && y > 0) || (py > 0 && y < 0)) {
                    xTmpArr[xTmpArrIdx++] = x;

                    if (xTmpArrIdx == 2) {
                        xTmpArrIdx = 0;

                        if (xTmpArr[0] < xTmpArr[1]) {
                            pars.add(new Par('(', xTmpArr[0]));
                            pars.add(new Par(')', xTmpArr[1]));
                        } else {
                            pars.add(new Par('(', xTmpArr[1]));
                            pars.add(new Par(')', xTmpArr[0]));
                        }
                    }
                }
            }

            px = x;
            py = y;
        }

        Collections.sort(pars);
        int curDepth = 0;
        int curBigCount = 0;
        int curSmallCount = 0;
        char prevPar = '.';

        for (Par par : pars) {
            if (par.par == '(') {
                curDepth++;
            } else {
                if (--curDepth == 0) {
                    curBigCount++;
                }

                if (prevPar == '(') {
                    curSmallCount++;
                }
            }

            prevPar = par.par;
        }

        System.out.printf("%d %d%n", curBigCount, curSmallCount);
        br.close();
    }

}
