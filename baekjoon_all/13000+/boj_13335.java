// Solve 2024-01-27

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj_13335 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        Queue<Integer> trucksIn = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            trucksIn.add(Integer.parseInt(st.nextToken()));
        }

        int curTime = 0;
        int curWeightSum = 0;
        Queue<int[]> trucksOut = new LinkedList<>();

        while (true) {
            curTime++;

            if (!trucksOut.isEmpty() && trucksOut.peek()[1] == curTime) {
                curWeightSum -= trucksOut.poll()[0];
            }

            if (!trucksIn.isEmpty() && curWeightSum + trucksIn.peek() <= l) {
                int truck = trucksIn.poll();
                curWeightSum += truck;
                trucksOut.add(new int[] { truck, curTime + w });
            }

            if (trucksIn.isEmpty() && trucksOut.isEmpty()) break;
        }

        System.out.println(curTime);
    }

}
