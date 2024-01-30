// Solve 2024-01-29

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_17478 {

    static int n;
    static StringBuilder sb;
    static String blank = "____";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        sb = new StringBuilder();
        sb.append("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
        print(0);
        System.out.println(sb);
        br.close();
    }

    static void printBlank(int depth) {
        int iter = depth;

        while (iter-- > 0) {
            sb.append(blank);
        }
    }

    static void print(int depth) {
        printBlank(depth);
        sb.append("\"재귀함수가 뭔가요?\"\n");

        if (depth == n) {
            printBlank(depth);
            sb.append("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
        } else {
            printBlank(depth);
            sb.append("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");

            printBlank(depth);
            sb.append("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");

            printBlank(depth);
            sb.append("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");

            print(depth + 1);
        }

        printBlank(depth);
        sb.append("라고 답변하였지.\n");
    }

}
