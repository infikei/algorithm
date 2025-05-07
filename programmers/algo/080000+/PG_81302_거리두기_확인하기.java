// Solve 2025-05-03

import java.util.*;

class PG_81302_거리두기_확인하기 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    public int[] solution(String[][] places) {
        int[] answer = new int[5];

        for (int i = 0; i < 5; i++) {
            answer[i] = isSafePlace(places[i]);
        }

        return answer;
    }

    int isSafePlace(String[] place) {
        ArrayList<Point> people = new ArrayList<Point>();

        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                if (place[x].charAt(y) == 'P') {
                    people.add(new Point(x, y));
                }
            }
        }

        for (Point person : people) {
            ArrayDeque<Point> bfsQue = new ArrayDeque<Point>();
            boolean[][] visited = new boolean[5][5];
            visited[person.x][person.y] = true;
            bfsQue.addLast(person);

            for (int dist = 1; dist <= 2; dist++) {
                int iter = bfsQue.size();

                while (iter-- > 0) {
                    Point curPos = bfsQue.pollFirst();

                    for (int d = 0; d < 4; d++) {
                        int nx = curPos.x + dx[d];
                        int ny = curPos.y + dy[d];

                        if (!isInRange(nx, ny) || place[nx].charAt(ny) == 'X' || visited[nx][ny]) continue;

                        if (place[nx].charAt(ny) == 'P') {
                            return 0;
                        }

                        visited[nx][ny] = true;
                        bfsQue.addLast(new Point(nx, ny));
                    }
                }
            }
        }

        return 1;
    }

    boolean isInRange(int x, int y) {
        return x >= 0 && x < 5 && y >= 0 && y < 5;
    }

}
