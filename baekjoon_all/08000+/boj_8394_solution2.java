// Solve 2024-05-19

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_8394_solution2 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        // 일의 자리 숫자가 60번마다 반복된다.
        String s = "123583145943707741561785381909987527965167303369549325729101";

        System.out.println(s.charAt((n - 1) % 60));
        br.close();
    }

}
