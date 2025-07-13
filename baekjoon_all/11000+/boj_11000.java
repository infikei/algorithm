// Solve 2024-05-17
// Update 2025-07-13

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj_11000 {

    static class Pair implements Comparable<Pair> {
        int s, e;

        Pair(int s, int e) {
            this.s = s;
            this.e = e;
        }

        @Override
        public int compareTo(Pair p) {
            return this.s - p.s;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        Pair[] lectures = new Pair[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            lectures[i] = new Pair(s, e);
        }

        Arrays.sort(lectures);
        int ans = 0;
        PriorityQueue<Integer> pqMinTop = new PriorityQueue<Integer>();

        for (Pair lecture : lectures) {
            while (!pqMinTop.isEmpty() && pqMinTop.peek() <= lecture.s) {
                pqMinTop.poll();
            }

            pqMinTop.add(lecture.e);
            ans = Math.max(ans, pqMinTop.size());
        }

        System.out.println(ans);
    }

}
