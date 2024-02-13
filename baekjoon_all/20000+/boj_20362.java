// Solve 2024-02-12

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_20362 {

    static class Chat {
        String name, content;

        Chat(String name, String content) {
            this.name = name;
            this.content = content;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        String winnerName = st.nextToken();
        String winnerContent = "";
        Chat[] chatting = new Chat[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            String name = st.nextToken();
            String content = st.nextToken();
            chatting[i] = new Chat(name, content);

            if (name.equals(winnerName)) {
                winnerContent = content;
            }
        }

        int losersCount = 0;

        for (Chat chat : chatting) {
            if (chat.name.equals(winnerName)) break;

            if (chat.content.equals(winnerContent)) {
                losersCount++;
            }
        }

        System.out.println(losersCount);
        br.close();
    }

}
