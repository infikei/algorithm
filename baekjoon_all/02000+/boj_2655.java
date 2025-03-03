// Solve 2025-03-03

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_2655 {

    static class Brick implements Comparable<Brick> {
        int num;
        int area;
        int height;
        int weight;
        int sumHeight;
        int prevIdx;

        Brick(int num, int area, int height, int weight) {
            this.num = num;
            this.area = area;
            this.height = height;
            this.weight = weight;
        }

        @Override
        public int compareTo(Brick o) {
            return area - o.area;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        Brick[] bricks = new Brick[n];
        StringTokenizer st;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int area = Integer.parseInt(st.nextToken());
            int height = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            bricks[i] = new Brick(i + 1, area, height, weight);
        }

        Arrays.sort(bricks);

        for (int i = 0; i < n; i++) {
            int maxSumHeight = -1;
            int prevIdx = -1;

            for (int j = 0; j < i; j++) {
                if (bricks[j].weight < bricks[i].weight && bricks[j].sumHeight > maxSumHeight) {
                    maxSumHeight = bricks[j].sumHeight;
                    prevIdx = j;
                }
            }

            if (prevIdx == -1) {
                bricks[i].sumHeight = bricks[i].height;
                bricks[i].prevIdx = -1;
            } else {
                bricks[i].sumHeight = bricks[i].height + maxSumHeight;
                bricks[i].prevIdx = prevIdx;
            }
        }

        int maxSumHeight = 0;
        int idxOfMaxSumHeight = 0;

        for (int i = 0; i < n; i++) {
            if (bricks[i].sumHeight > maxSumHeight) {
                maxSumHeight = bricks[i].sumHeight;
                idxOfMaxSumHeight = i;
            }
        }

        ArrayDeque<Integer> stack = new ArrayDeque<Integer>();
        int curIdx = idxOfMaxSumHeight;

        while (curIdx != -1) {
            stack.addLast(bricks[curIdx].num);
            curIdx = bricks[curIdx].prevIdx;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(stack.size()).append('\n');

        while (!stack.isEmpty()) {
            sb.append(stack.pollLast()).append('\n');
        }

        System.out.println(sb);
    }

}
