// Solve 2024-08-10

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_31994 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String maxSeminarName = "";
        int maxApplicantNum = 0;

        for (int i = 0; i < 7; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            String seminarName = st.nextToken();
            int applicantNum = Integer.parseInt(st.nextToken());

            if (applicantNum > maxApplicantNum) {
                maxApplicantNum = applicantNum;
                maxSeminarName = seminarName;
            }
        }

        System.out.println(maxSeminarName);
        br.close();
    }

}
