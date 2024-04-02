// Solve 2024-04-01

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_9205_union_find {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        int getDist(Point p) {
            return Math.abs(this.x - p.x) + Math.abs(this.y - p.y);
        }
    }

    static Point[] points;
    static int[] parent = new int[102];

    static int getParentOf(int u) {
        if (parent[u] < 0) return u;

        return parent[u] = getParentOf(parent[u]);
    }

    static void unionParents(int u1, int u2) {
        int pu1 = getParentOf(u1);
        int pu2 = getParentOf(u2);

        if (pu1 != pu2) {
            if (parent[pu1] < parent[pu2]) {
                parent[pu1] += parent[pu2];
                parent[pu2] = pu1;
            } else {
                parent[pu2] += parent[pu1];
                parent[pu1] = pu2;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            points = new Point[n + 2];

            for (int u = 0; u < n + 2; u++) {
                st = new StringTokenizer(br.readLine(), " ");
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                points[u] = new Point(x, y);
                parent[u] = -1;
            }

            for (int u1 = 0; u1 < n + 2; u1++) {
                for (int u2 = u1 + 1; u2 < n + 2; u2++) {
                    if (points[u1].getDist(points[u2]) <= 1000) {
                        unionParents(u1, u2);
                    }
                }
            }

            sb.append(getParentOf(0) == getParentOf(n + 1) ? "happy\n" : "sad\n");
        }

        System.out.print(sb);
        br.close();
    }

}
