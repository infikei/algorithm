// Solve 2024-02-26
// Update 2025-03-04

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class boj_14865 {

    static class XCrossInfo implements Comparable<XCrossInfo> {
        int x;
        char par;

        XCrossInfo(int x, char par) {
            this.x = x;
            this.par = par;
        }

        @Override
        public int compareTo(XCrossInfo o) {
            return Integer.compare(x, o.x);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        StringTokenizer st;
        int[][] points = new int[n][2];
        int[] bottomLeftPoint = { Integer.MAX_VALUE, Integer.MAX_VALUE };
        int idxOfBottomLeftPoint = 0;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            points[i][0] = Integer.parseInt(st.nextToken());
            points[i][1] = Integer.parseInt(st.nextToken());

            // 점들 중에서 가장 왼쪽 아래에 있는 점을 찾는다.
            if (points[i][0] < bottomLeftPoint[0] || (points[i][0] == bottomLeftPoint[0] && points[i][1] < bottomLeftPoint[1])) {
                bottomLeftPoint[0] = points[i][0];
                bottomLeftPoint[1] = points[i][1];
                idxOfBottomLeftPoint = i;
            }
        }

        // x축과 교차하는 점의 x좌표와 몇번째로 교차하는지 정보를 담는다.
        ArrayList<XCrossInfo> xCrossInfoList = new ArrayList<XCrossInfo>();
        int[] tmpX = new int[2];
        int idxOftmpX = 0;
        int px = bottomLeftPoint[0];
        int py = bottomLeftPoint[1];

        for (int i = 1, j = idxOfBottomLeftPoint + 1; i < n; i++, j++) {
            if (j >= n) {
                j -= n;
            }

            int x = points[j][0];
            int y = points[j][1];

            if (px == x && ((py < 0 && y > 0) || (py > 0 && y < 0))) {
                tmpX[idxOftmpX] = x;
                idxOftmpX++;

                if (idxOftmpX == 2) {
                    idxOftmpX = 0;

                    if (tmpX[0] < tmpX[1]) {
                        xCrossInfoList.add(new XCrossInfo(tmpX[0], '('));
                        xCrossInfoList.add(new XCrossInfo(tmpX[1], ')'));
                    } else {
                        xCrossInfoList.add(new XCrossInfo(tmpX[1], '('));
                        xCrossInfoList.add(new XCrossInfo(tmpX[0], ')'));
                    }
                }
            }

            px = x;
            py = y;
        }

        Collections.sort(xCrossInfoList);
        int depth = 0;
        int bigCnt = 0;
        int smallCnt = 0;
        char prevPar = '.';

        for (XCrossInfo xCrossInfo : xCrossInfoList) {
            if (xCrossInfo.par == '(') {
                depth++;
            } else {
                depth--;

                if (depth == 0) {
                    bigCnt++;
                }

                if (prevPar == '(') {
                    smallCnt++;
                }
            }

            prevPar = xCrossInfo.par;
        }

        System.out.printf("%d %d%n", bigCnt, smallCnt);
    }

}
