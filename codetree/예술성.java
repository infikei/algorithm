// Solve 2024-02-22

// 코드트리에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class 예술성 {

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };
    static int n;
    static int[][] board;
    static int[][] boardCopy;
    static int[][] group;
    static ArrayList<int[]> groupInfo;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        board = new int[n][n];
        boardCopy = new int[n][n];
        group = new int[n][n];

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < n; y++) {
                board[x][y] = Integer.parseInt(st.nextToken());
            }
        }

        int harmonySum = 0;

        initGroups();
        harmonySum += getHarmony();

        for (int i = 1; i <= 3; i++) {
            rotate();
            initGroups();
            harmonySum += getHarmony();
        }

        System.out.println(harmonySum);
        br.close();
    }

    static void initGroups() {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                group[x][y] = 0;
            }
        }

        int curGroup = 0;
        groupInfo = new ArrayList<int[]>();
        groupInfo.add(null);

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (group[x][y] != 0) continue;

                group[x][y] = ++curGroup;
                ArrayDeque<int[]> bfsQue = new ArrayDeque<int[]>();
                bfsQue.offer(new int[] { x, y });
                int area = 1;

                while (!bfsQue.isEmpty()) {
                    int[] curPos = bfsQue.poll();

                    for (int d = 0; d < 4; d++) {
                        int nx = curPos[0] + dx[d];
                        int ny = curPos[1] + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n || group[nx][ny] != 0 || board[nx][ny] != board[x][y]) continue;

                        group[nx][ny] = curGroup;
                        bfsQue.offer(new int[] { nx, ny });
                        area++;
                    }
                }

                groupInfo.add(new int[] { x, y, area });
            }
        }
    }

    static int getHarmony() {
        int harmony = 0;
        boolean[][] visited = new boolean[n][n];

        for (int curGroup = 1; curGroup < groupInfo.size(); curGroup++) {
            int[] adjCount = new int[groupInfo.size()];

            int curGroupX = groupInfo.get(curGroup)[0];
            int curGroupY = groupInfo.get(curGroup)[1];
            int curGroupArea = groupInfo.get(curGroup)[2];
            visited[curGroupX][curGroupY] = true;
            ArrayDeque<int[]> bfsQue = new ArrayDeque<int[]>();
            bfsQue.offer(new int[] { curGroupX, curGroupY });

            while (!bfsQue.isEmpty()) {
                int[] curPos = bfsQue.poll();

                for (int d = 0; d < 4; d++) {
                    int nx = curPos[0] + dx[d];
                    int ny = curPos[1] + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;

                    if (group[nx][ny] == curGroup) {
                        visited[nx][ny] = true;
                        bfsQue.offer(new int[] { nx, ny });
                    } else {
                        adjCount[group[nx][ny]]++;
                    }
                }
            }

            for (int nextGroup = curGroup + 1; nextGroup < groupInfo.size(); nextGroup++) {
                int nextGroupX = groupInfo.get(nextGroup)[0];
                int nextGroupY = groupInfo.get(nextGroup)[1];
                int nextGroupArea = groupInfo.get(nextGroup)[2];
                harmony += (curGroupArea + nextGroupArea) * board[curGroupX][curGroupY] * board[nextGroupX][nextGroupY] * adjCount[nextGroup];
            }
        }

        return harmony;
    }

    static void rotate() {
        int subSize = n / 2;

        for (int x = 0; x < subSize; x++) {
            for (int y = 0; y < subSize; y++) {
                boardCopy[x][y] = board[subSize - 1 - y][x];
            }
        }

        for (int x = 0; x < subSize; x++) {
            for (int y = 0; y < subSize; y++) {
                boardCopy[subSize + 1 + x][y] = board[n - 1 - y][x];
            }
        }

        for (int x = 0; x < subSize; x++) {
            for (int y = 0; y < subSize; y++) {
                boardCopy[x][subSize + 1 + y] = board[subSize - 1 - y][subSize + 1 + x];
            }
        }

        for (int x = 0; x < subSize; x++) {
            for (int y = 0; y < subSize; y++) {
                boardCopy[subSize + 1 + x][subSize + 1 + y] = board[n - 1 - y][subSize + 1 + x];
            }
        }

        for (int x = 0; x < n; x++) {
            boardCopy[x][subSize] = board[subSize][n - 1 - x];
        }

        for (int y = 0; y < n; y++) {
            boardCopy[subSize][y] = board[y][subSize];
        }

        int[][] boardTmp = board;
        board = boardCopy;
        boardCopy = boardTmp;
        boardTmp = null;
    }

}
