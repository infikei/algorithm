// Solve 2024-02-09

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_31403 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String aStr = br.readLine();
        String bStr = br.readLine();
        String cStr = br.readLine();
        int c = Integer.parseInt(cStr);

        System.out.println(Integer.parseInt(aStr) + Integer.parseInt(bStr) - c);
        System.out.println(Integer.parseInt(aStr + bStr) - c);
        br.close();
    }

}
