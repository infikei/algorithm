// Solve 2023-10-19
// Update 2023-10-23

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_25304 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int totalAmountOnReceipt = Integer.parseInt(br.readLine());
        int itemsNum = Integer.parseInt(br.readLine());
        int totalAmountCalculated = 0;

        for (int itemsIdx = 0; itemsIdx < itemsNum; itemsIdx++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int itemPrice = Integer.parseInt(st.nextToken());
            int itemCount = Integer.parseInt(st.nextToken());

            totalAmountCalculated += itemPrice * itemCount;
        }

        if (totalAmountOnReceipt == totalAmountCalculated) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        br.close();
    }
}
