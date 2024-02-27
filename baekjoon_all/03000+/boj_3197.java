// Solve 2024-02-26

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class boj_3197 {

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };
    static int[] parent;

    static int getParentOf(int u) {
        if (parent[u] < 0) return u;
        return parent[u] = getParentOf(parent[u]);
    }

    static void unionParents(int u1, int u2) {
        int pu1 = getParentOf(u1);
        int pu2 = getParentOf(u2);

        if (pu1 != pu2) {
            if (parent[pu1] <= parent[pu2]) {
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
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        char[][] board = new char[r][c];
        int[][] people = new int[2][2];
        int peopleFound = 0;

        for (int x = 0; x < r; x++) {
            String row = br.readLine();

            for (int y = 0; y < c; y++) {
                board[x][y] = row.charAt(y);

                if (board[x][y] == 'L') {
                    people[peopleFound][0] = x;
                    people[peopleFound++][1] = y;
                }
            }
        }

        ArrayDeque<int[]> bfsQueIce = new ArrayDeque<int[]>();
        ArrayDeque<int[]> bfsQueLand = new ArrayDeque<int[]>();
        int[][] group = new int[r][c];
        int groupIdx = 0;

        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                if (board[x][y] == 'X' || group[x][y] > 0) continue;

                group[x][y] = ++groupIdx;
                bfsQueLand.offer(new int[] { x, y });

                while (!bfsQueLand.isEmpty()) {
                    int[] curPos = bfsQueLand.poll();

                    for (int d = 0; d < 4; d++) {
                        int nx = curPos[0] + dx[d];
                        int ny = curPos[1] + dy[d];

                        if (nx < 0 || nx >= r || ny < 0 || ny >= c || group[nx][ny] > 0) continue;

                        group[nx][ny] = groupIdx;

                        if (board[nx][ny] == 'X') {
                            bfsQueIce.offer(new int[] { nx, ny });
                        } else {
                            bfsQueLand.offer(new int[] { nx, ny });
                        }
                    }
                }
            }
        }

        parent = new int[groupIdx + 1];

        for (int u = 1; u <= groupIdx; u++) {
            parent[u] = -1;
        }

        int curDay = 0;
        int groupOfP1 = group[people[0][0]][people[0][1]];
        int groupOfP2 = group[people[1][0]][people[1][1]];

        while (true) {
            if (getParentOf(groupOfP1) == getParentOf(groupOfP2)) {
                break;
            }

            int curIter = bfsQueIce.size();

            while (curIter-- > 0) {
                int[] curPos = bfsQueIce.poll();
                board[curPos[0]][curPos[1]] = '.';

                for (int d = 0; d < 4; d++) {
                    int nx = curPos[0] + dx[d];
                    int ny = curPos[1] + dy[d];

                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

                    if (board[nx][ny] != 'X') {
                        unionParents(group[curPos[0]][curPos[1]], group[nx][ny]);
                    } else if (group[nx][ny] == 0) {
                        bfsQueIce.offer(new int[] { nx, ny });
                        group[nx][ny] = group[curPos[0]][curPos[1]];
                    }
                }
            }

            curDay++;
        }

        System.out.println(curDay);
        br.close();
    }

}
