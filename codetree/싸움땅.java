// Solve 2024-03-27

// 코드트리에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 싸움땅 {

    static class Player {
        int id, x, y, d, s;
        int gun = 0;

        Player(int id, int x, int y, int d, int s) {
            this.id = id;
            this.x = x;
            this.y = y;
            this.d = d;
            this.s = s;
        }

        void getGun() {
            if (!gunBoard[x][y].isEmpty()) {
                gun = gunBoard[x][y].poll();
            }
        }

        void putGun() {
            if (gun > 0) {
                gunBoard[x][y].offer(gun);
                gun = 0;
            }
        }

        void changeGun() {
            putGun();
            getGun();
        }

        void move() {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                d = d < 2 ? d + 2 : d - 2;
                nx = x + dx[d];
                ny = y + dy[d];
            }

            playerBoard[x][y] = null;
            x = nx;
            y = ny;

            if (playerBoard[x][y] == null) {
                playerBoard[x][y] = this;
                changeGun();
            } else {
                Player other = playerBoard[x][y];
                playerBoard[x][y] = null;

                int thisAttack = this.s + this.gun;
                int otherAttack = other.s + other.gun;

                if (thisAttack > otherAttack) {
                    playerScore[this.id] += thisAttack - otherAttack;
                    playerBoard[x][y] = this;
                    other.moveAfterLose();
                    this.changeGun();
                } else if (thisAttack < otherAttack) {
                    playerScore[other.id] += otherAttack - thisAttack;
                    playerBoard[x][y] = other;
                    this.moveAfterLose();
                    other.changeGun();
                } else if (this.s > other.s) {
                    playerBoard[x][y] = this;
                    other.moveAfterLose();
                    this.changeGun();
                } else {
                    playerBoard[x][y] = other;
                    this.moveAfterLose();
                    other.changeGun();
                }
            }
        }

        void moveAfterLose() {
            putGun();

            int nx = x + dx[d];
            int ny = y + dy[d];

            while (nx < 0 || nx >= n || ny < 0 || ny >= n || playerBoard[nx][ny] != null) {
                if (++d == 4) {
                    d = 0;
                }

                nx = x + dx[d];
                ny = y + dy[d];
            }

            x = nx;
            y = ny;
            playerBoard[x][y] = this;
            getGun();
        }
    }

    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, 1, 0, -1 };
    static int n, m;
    static PriorityQueue<Integer>[][] gunBoard;
    static Player[][] playerBoard;
    static int[] playerScore;
    static Comparator<Integer> cmp = new Comparator<Integer>() {

        public int compare(Integer o1, Integer o2) {
            return o1 < o2 ? 1 : o1 > o2 ? -1 : 0;
        };

    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        gunBoard = new PriorityQueue[n][n];
        playerBoard = new Player[n][n];
        Player[] players = new Player[m + 1];
        playerScore = new int[m + 1];

        for (int x = 0; x < n; x++) {
            st = new StringTokenizer(br.readLine(), " ");

            for (int y = 0; y < n; y++) {
                gunBoard[x][y] = new PriorityQueue<Integer>(cmp);
                int curNum = Integer.parseInt(st.nextToken());

                if (curNum > 0) {
                    gunBoard[x][y].offer(curNum);
                }
            }
        }

        for (int id = 1; id <= m; id++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            int d = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            players[id] = new Player(id, x, y, d, s);
            playerBoard[x][y] = players[id];
        }

        for (int round = 1; round <= k; round++) {
            for (int id = 1; id <= m; id++) {
                players[id].move();
            }
        }

        for (int id = 1; id <= m; id++) {
            sb.append(playerScore[id]).append(" ");
        }

        System.out.println(sb);
        br.close();
    }

}
