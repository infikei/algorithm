// Solve 2024-05-30

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_19941 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        char[] arr = br.readLine().toCharArray();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') {
                for (int j = i - k; j <= i + k; j++) {
                    if (j < 0 || j >= n) {
                        continue;
                    }

                    if (arr[j] == 'H') {
                        arr[j] = ' ';
                        ans++;
                        break;
                    }
                }
            }
        }

        System.out.println(ans);
        br.close();
    }

}
