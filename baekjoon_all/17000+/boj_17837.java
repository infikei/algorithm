// Solve 2024-02-10

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_17837 {

    static int[] dx = { 0, 0, 0, -1, 1 };
    static int[] dy = { 0, 1, -1, 0, 0 };
    static int n, k;
    static Node[][] board;
    static Horse[] horses;

    static class Horse {
        int x, y, d;

        Horse(int x, int y, int d) {
            this.x = x;
            this.y = y;
            this.d = d;
        }

        void setPos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Node {
        int color;
        ArrayList<Integer> horseList;

        Node(int color) {
            this.color = color;
            this.horseList = new ArrayList<Integer>();
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        board = new Node[n + 1][n + 1];
        horses = new Horse[k + 1];

        for (int x = 1; x <= n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 1; y <= n; y++) {
                int color = Integer.parseInt(st.nextToken());
                board[x][y] = new Node(color);
            }
        }

        for (int horseIdx = 1; horseIdx <= k; horseIdx++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            horses[horseIdx] = new Horse(x, y, d);
            board[x][y].horseList.add(horseIdx);
        }

        int curTurn = 0;

        loop: while (++curTurn <= 1000) {
            for (int horseIdx = 1; horseIdx <= k; horseIdx++) {
                int x = horses[horseIdx].x;
                int y = horses[horseIdx].y;
                int d = horses[horseIdx].d;
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny].color == 2) {
                    d = d <= 2 ? 3 - d : 7 - d;
                    horses[horseIdx].d = d;
                    nx = x + dx[d];
                    ny = y + dy[d];

                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                        if (board[nx][ny].color == 1) {
                            reverseMove(x, y, nx, ny, horseIdx);

                            if (board[nx][ny].horseList.size() >= 4) break loop;
                        } else if (board[nx][ny].color == 0) {
                            move(x, y, nx, ny, horseIdx);

                            if (board[nx][ny].horseList.size() >= 4) break loop;
                        }
                    }
                } else if (board[nx][ny].color == 1) {
                    reverseMove(x, y, nx, ny, horseIdx);

                    if (board[nx][ny].horseList.size() >= 4) break loop;
                } else {
                    move(x, y, nx, ny, horseIdx);

                    if (board[nx][ny].horseList.size() >= 4) break loop;
                }
            }
        }

        if (curTurn >= 1001) {
            curTurn = -1;
        }

        System.out.println(curTurn);
        br.close();
    }

    static void move(int x, int y, int nx, int ny, int horseIdx) {
        ArrayList<Integer> fromList = board[x][y].horseList;
        ArrayList<Integer> tmpList = new ArrayList<Integer>();
        ArrayList<Integer> toList = board[nx][ny].horseList;

        while (true) {
            int curHorseIdx = fromList.remove(fromList.size() - 1);
            tmpList.add(curHorseIdx);

            if (curHorseIdx == horseIdx) break;
        }

        while (!tmpList.isEmpty()) {
            int curHorseIdx = tmpList.remove(tmpList.size() - 1);
            toList.add(curHorseIdx);
            horses[curHorseIdx].setPos(nx, ny);
        }
    }

    static void reverseMove(int x, int y, int nx, int ny, int horseIdx) {
        ArrayList<Integer> fromList = board[x][y].horseList;
        ArrayList<Integer> toList = board[nx][ny].horseList;

        while (true) {
            int curHorseIdx = fromList.remove(fromList.size() - 1);
            toList.add(curHorseIdx);
            horses[curHorseIdx].setPos(nx, ny);

            if (curHorseIdx == horseIdx) break;
        }
    }

}
