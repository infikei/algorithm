// Solve 2024-02-28

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class swea_1767 {

    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, 1, 0, -1 };
    static int n;
    static int[][] board;
    static ArrayList<int[]> cores;
    static int maxConnectedCount;
    static int minLength;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            n = Integer.parseInt(br.readLine());
            board = new int[n][n];
            cores = new ArrayList<int[]>();

            for (int x = 0; x < n; x++) {
                st = new StringTokenizer(br.readLine(), " ");

                for (int y = 0; y < n; y++) {
                    board[x][y] = st.nextToken().charAt(0) - '0';

                    if (board[x][y] == 1 && x != 0 && x != n - 1 && y != 0 && y != n - 1) {
                        cores.add(new int[] { x, y });
                    }
                }
            }

            maxConnectedCount = 0;
            minLength = Integer.MAX_VALUE;
            recur(0, 0, 0);
            sb.append("#").append(ti).append(" ").append(minLength).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

    static void recur(int depth, int curConnectedCount, int curLength) {
        if (depth == cores.size()) {
            if (curConnectedCount > maxConnectedCount) {
                maxConnectedCount = curConnectedCount;
                minLength = curLength;
            } else if (curConnectedCount == maxConnectedCount && curLength < minLength) {
                minLength = curLength;
            }

            return;
        }

        recur(depth + 1, curConnectedCount, curLength);

        for (int d = 0; d < 4; d++) {
            int nx = cores.get(depth)[0] + dx[d];
            int ny = cores.get(depth)[1] + dy[d];
            boolean valid = true;
            int nextLength = curLength;
            int curNum = -(depth + 1);

            while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (board[nx][ny] != 0) {
                    valid = false;
                    break;
                }

                board[nx][ny] = curNum;
                nextLength++;
                nx += dx[d];
                ny += dy[d];
            }

            if (valid) {
                recur(depth + 1, curConnectedCount + 1, nextLength);
            }

            nx = cores.get(depth)[0] + dx[d];
            ny = cores.get(depth)[1] + dy[d];

            while (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == curNum) {
                board[nx][ny] = 0;
                nx += dx[d];
                ny += dy[d];
            }
        }
    }

}
