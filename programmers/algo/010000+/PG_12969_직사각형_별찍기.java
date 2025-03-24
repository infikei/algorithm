// Solve 2024-06-08
// Update 2024-06-20

// 프로그래머스에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.io.*;
import java.util.*;

class PG_12969_직사각형_별찍기 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sb.append("*");
            }
            
            sb.append("\n");
        }
        
        System.out.print(sb);
    }

}
