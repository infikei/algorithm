// Solve 2024-08-26

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_25286 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int yy = Integer.parseInt(st.nextToken());
            int mm = Integer.parseInt(st.nextToken());

            switch (mm) {
                case 1:
                    sb.append(yy - 1).append(" 12 31\n");
                    break;
                case 3:
                    if (yy % 4 == 0 && yy != 2100) {
                        sb.append(yy).append(" 2 29\n");
                    } else {
                        sb.append(yy).append(" 2 28\n");
                    }
                    break;
                case 2:
                case 4:
                case 6:
                case 8:
                case 9:
                case 11:
                    sb.append(yy).append(' ').append(mm - 1).append(" 31\n");
                    break;
                case 5:
                case 7:
                case 10:
                case 12:
                    sb.append(yy).append(' ').append(mm - 1).append(" 30\n");
                    break;
                default:
                    break;
            }
        }

        System.out.print(sb);
        br.close();
    }

}
