// Solve 2024-05-19

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_8394 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        n %= 60; // 일의 자리 숫자가 60번마다 반복된다.

        int[] arr = new int[3];
        arr[2] = 1;

        for (int i = 0; i < n; i++) {
            arr[0] = arr[1];
            arr[1] = arr[2];
            arr[2] = (arr[0] + arr[1]) % 10;
        }

        System.out.println(arr[2]);
        br.close();
    }

}
