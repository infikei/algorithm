// Solve 2024-01-24

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_13223 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), ":");
        int curTime = Integer.parseInt(st.nextToken());
        curTime = curTime * 60 + Integer.parseInt(st.nextToken());
        curTime = curTime * 60 + Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine(), ":");
        int targetTime = Integer.parseInt(st.nextToken());
        targetTime = targetTime * 60 + Integer.parseInt(st.nextToken());
        targetTime = targetTime * 60 + Integer.parseInt(st.nextToken());

        int dt = targetTime - curTime;

        if (dt <= 0) {
            dt += 86400;
        }

        System.out.printf("%02d:%02d:%02d%n", dt / 3600, dt % 3600 / 60, dt % 60);
    }

}
