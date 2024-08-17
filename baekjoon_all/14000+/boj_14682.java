// Solve 2024-08-06

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_14682 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());
        int ans = 0;

        switch (k) {
            case 0:
                ans = n;
                break;
            case 1:
                ans = n * 11;
                break;
            case 2:
                ans = n * 111;
                break;
            case 3:
                ans = n * 1111;
                break;
            case 4:
                ans = n * 11111;
                break;
            case 5:
                ans = n * 111111;
                break;
            default:
                break;
        }

        System.out.println(ans);
        br.close();
    }

}
