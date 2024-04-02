// Solve 2024-04-02

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class boj_10826 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        BigInteger[] fibonacci = new BigInteger[3];
        fibonacci[0] = new BigInteger("0");
        fibonacci[1] = new BigInteger("0");
        fibonacci[2] = new BigInteger("1");

        for (int i = 2; i <= n; i++) {
            fibonacci[0] = fibonacci[1];
            fibonacci[1] = fibonacci[2];
            fibonacci[2] = fibonacci[0].add(fibonacci[1]);
        }

        if (n == 0) {
            fibonacci[2] = BigInteger.valueOf(0);
        }

        System.out.println(fibonacci[2]);
        br.close();
    }

}
