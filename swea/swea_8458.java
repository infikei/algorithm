// Solve 2024-04-01

// SWEA에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_8458 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        for (int ti = 1; ti <= t; ti++) {
            int n = Integer.parseInt(br.readLine());
            boolean valid = true;

            // 각 좌표마다 원점까지의 최단거리를 구하고 그 중 최댓값만 저장한다.
            st = new StringTokenizer(br.readLine(), " ");
            int maxDist = Math.abs(Integer.parseInt(st.nextToken())) + Math.abs(Integer.parseInt(st.nextToken()));

            for (int i = 1; i < n; i++) {
                String line = br.readLine();

                if (valid) {
                    st = new StringTokenizer(line, " ");
                    int curDist = Math.abs(Integer.parseInt(st.nextToken())) + Math.abs(Integer.parseInt(st.nextToken()));

                    // 모든 최단거리에 대해 짝수 홀수 여부가 일치하지 않는다면 불가능한 경우이다.
                    if (maxDist % 2 != curDist % 2) {
                        valid = false;
                    }

                    maxDist = curDist > maxDist ? curDist : maxDist;
                }
            }

            // 모든 최단거리에 대해 짝수 홀수 여부가 일치하지 않는다면 불가능한 경우이므로 -1을 출력한다.
            if (!valid) {
                sb.append("#").append(ti).append(" ").append(-1).append("\n");
                continue;
            }

            // k * (k + 1) / 2로 나타낼 수 있고 maxDist 이상인 정수 중 최솟값에 해당하는 정수 k를 이분탐색으로 구한다.
            // 정수 k는 이분탐색 수행 이후 high 변수에 저장된다.
            long low = -1; // false를 가리킨다.
            long high = 70000; // true를 가리킨다.

            while (low + 1 < high) {
                long mid = (low + high) / 2;
                long midSum = mid * (mid + 1) / 2;

                if (midSum >= maxDist) {
                    high = mid;
                } else {
                    low = mid;
                }
            }

            // k * (k + 1) / 2와 maxDist의 짝수 홀수 여부가 일치하지 않을 경우 high를 1씩 증가한다.
            while (high * (high + 1) / 2 % 2 != maxDist % 2) {
                high++;
            }

            sb.append("#").append(ti).append(" ").append(high).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
