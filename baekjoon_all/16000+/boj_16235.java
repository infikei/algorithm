// Solve 2025-06-08

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class boj_16235 {

    static int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[][] a = new int[n + 1][n + 1];
        int[][] ground = new int[n + 1][n + 1];
        List<List<ArrayDeque<Integer>>> trees = new ArrayList<>();
        trees.add(null);

        for (int x = 1; x <= n; x++) {
            st = new StringTokenizer(br.readLine(), " ");
            trees.add(new ArrayList<ArrayDeque<Integer>>());
            trees.get(x).add(null);

            for (int y = 1; y <= n; y++) {
                a[x][y] = Integer.parseInt(st.nextToken());
                ground[x][y] = 5;
                trees.get(x).add(new ArrayDeque<Integer>());
            }
        }

        while (m-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            trees.get(x).get(y).addLast(z);
        }

        int[][] foodInSummer = new int[n + 1][n + 1];
        int[][] spreadInAutumn = new int[n + 1][n + 1];

        while (k-- > 0) {
            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= n; y++) {
                    ArrayDeque<Integer> curTrees = trees.get(x).get(y);
                    int iter = curTrees.size();

                    while (iter-- > 0) {
                        int treeAge = curTrees.pollFirst();

                        if (ground[x][y] < treeAge) {
                            foodInSummer[x][y] += treeAge / 2;
                            continue;
                        }

                        ground[x][y] -= treeAge;
                        treeAge++;
                        curTrees.addLast(treeAge);

                        if (treeAge % 5 == 0) {
                            spreadInAutumn[x][y]++;
                        }
                    }
                }
            }

            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= n; y++) {
                    ground[x][y] += foodInSummer[x][y];
                    foodInSummer[x][y] = 0;
                }
            }

            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= n; y++) {
                    if (spreadInAutumn[x][y] == 0) continue;

                    int treeToAdd = spreadInAutumn[x][y];
                    spreadInAutumn[x][y] = 0;

                    for (int d = 0; d < 8; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

                        ArrayDeque<Integer> curTrees = trees.get(nx).get(ny);

                        for (int i = 0; i < treeToAdd; i++) {
                            curTrees.addFirst(1);
                        }
                    }
                }
            }

            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= n; y++) {
                    ground[x][y] += a[x][y];
                }
            }
        }

        int ans = 0;

        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                ans += trees.get(x).get(y).size();
            }
        }

        System.out.println(ans);
    }

}
