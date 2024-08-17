// Solve 2024-08-02

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1434 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine(), " ");
        int[] boxes = new int[n];

        for (int i = 0; i < n; i++) {
            boxes[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine(), " ");
        int[] books = new int[m];

        for (int j = 0; j < m; j++) {
            books[j] = Integer.parseInt(st.nextToken());
        }

        int wastedWeightSum = 0;
        int i = 0;

        for (int j = 0; j < m; j++) {
            while (books[j] > boxes[i]) {
                wastedWeightSum += boxes[i];
                i++;
            }

            boxes[i] -= books[j];
        }

        while (i < n) {
            wastedWeightSum += boxes[i];
            i++;
        }

        System.out.println(wastedWeightSum);
        br.close();
    }

}
