// Solve 2024-03-03

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class swea_2383 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            int n = Integer.parseInt(br.readLine());
            ArrayList<int[]> people = new ArrayList<int[]>();
            ArrayList<int[]> stairsInfo = new ArrayList<int[]>();

            for (int x = 0; x < n; x++) {
                st = new StringTokenizer(br.readLine(), " ");

                for (int y = 0; y < n; y++) {
                    int b = Integer.parseInt(st.nextToken());

                    if (b >= 2) {
                        stairsInfo.add(new int[] { x, y, b });
                    } else if (b == 1) {
                        people.add(new int[] { x, y });
                    }
                }
            }

            // people 배열의 저장할 값을 좌표에서 각 계단까지의 거리로 변환한다.
            for (int[] person : people) {
                int x = person[0];
                int y = person[1];
                person[0] = Math.abs(x - stairsInfo.get(0)[0]) + Math.abs(y - stairsInfo.get(0)[1]);
                person[1] = Math.abs(x - stairsInfo.get(1)[0]) + Math.abs(y - stairsInfo.get(1)[1]);
            }

            int minTime = Integer.MAX_VALUE;

            // 사람들을 두 개의 계단에 나누어 배정하는 모든 경우에 대해 완전 탐색한다.
            for (int selected = 0; selected < (1 << people.size()); selected++) {
                ArrayList<Integer>[] peopleTime = new ArrayList[2];
                ArrayDeque<Integer>[] stairTime = new ArrayDeque[2];

                for (int i = 0; i < 2; i++) {
                    peopleTime[i] = new ArrayList<Integer>();
                    stairTime[i] = new ArrayDeque<Integer>();
                    stairTime[i].offer(0);
                    stairTime[i].offer(0);
                    stairTime[i].offer(0);
                }

                for (int i = 0; i < people.size(); i++) {
                    if ((selected & 1 << i) == 0) {
                        peopleTime[0].add(people.get(i)[0]);
                    } else {
                        peopleTime[1].add(people.get(i)[1]);
                    }
                }

                // 각 계단마다 시간이 얼마나 걸리는지 계산한다.
                for (int i = 0; i < 2; i++) {
                    Collections.sort(peopleTime[i]);

                    for (int x : peopleTime[i]) {
                        int y = stairTime[i].poll();
                        stairTime[i].offer(Math.max(x, y) + stairsInfo.get(i)[2]);
                    }
                }

                // 두 개의 계단 중 더 오래 걸리는 시간이 답이 될 수 있는 후보이다.
                int curTime = Math.max(stairTime[0].peekLast(), stairTime[1].peekLast()) + 1;
                minTime = Math.min(minTime, curTime);
            }

            sb.append("#").append(ti).append(" ").append(minTime).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
