// Solve 2023-10-19

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_25304 {
    public static void main(String[] args) throws IOException {
        BufferedReader br;
        int totalAmountOnReceipt;
        int totalAmountCalculated;
        int itemsNum;

        br = new BufferedReader(new InputStreamReader(System.in));
        totalAmountOnReceipt = Integer.parseInt(br.readLine());
        itemsNum = Integer.parseInt(br.readLine());
        totalAmountCalculated = 0;

        for (int itemsIdx = 0; itemsIdx < itemsNum; itemsIdx++) {
            StringTokenizer st;
            int itemPrice;
            int itemCount;

            st = new StringTokenizer(br.readLine(), " ");
            itemPrice = Integer.parseInt(st.nextToken());
            itemCount = Integer.parseInt(st.nextToken());

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
