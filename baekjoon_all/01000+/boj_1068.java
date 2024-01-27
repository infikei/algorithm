// Solve 2024-01-23
// Update 2024-01-26

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class boj_1068 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        List<List<Integer>> children = new ArrayList<>();
        int rootNode = -1;

        for (int i = 0; i < n; i++) {
            children.add(new ArrayList<Integer>());
        }

        for (int u = 0; u < n; u++) {
            int parent = Integer.parseInt(st.nextToken());

            if (parent == -1) {
                rootNode = u;
            } else {
                children.get(parent).add(u);
            }
        }

        int erasedNode = Integer.parseInt(br.readLine());
        int ans = 0;
        Deque<Integer> deque = new LinkedList<>();

        if (rootNode != erasedNode) {
            deque.addLast(rootNode);
        }

        while (!deque.isEmpty()) {
            int curNode = deque.pollFirst();

            if (children.get(curNode).isEmpty()) {
                ans++;
            } else if (children.get(curNode).size() == 1 && children.get(curNode).get(0) == erasedNode) {
                ans++;
            } else {
                for (int child : children.get(curNode)) {
                    if (child != erasedNode) {
                        deque.addLast(child);
                    }
                }
            }
        }

        System.out.println(ans);
        br.close();
    }

}
