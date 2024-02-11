// Solve 2024-02-11

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_1927_solution2 {

    static class PqMinTop {
        private int[] heap;
        private int heapEnd;

        PqMinTop(int capacity) {
            heap = new int[capacity + 1];
            heapEnd = 1;
        }

        boolean isEmpty() {
            return heapEnd == 1;
        }

        int size() {
            return heapEnd - 1;
        }

        void push(int x) {
            int curNode = heapEnd++;
            int curParent = curNode / 2;

            while (curParent >= 1 && heap[curParent] > x) {
                heap[curNode] = heap[curParent];
                curNode = curParent;
                curParent /= 2;
            }

            heap[curNode] = x;
        }

        int pop() {
            if (isEmpty()) return 0;

            int valueReturn = heap[1];
            int valueMove = heap[--heapEnd];
            int curNode = 1;
            int curChild = 2;

            while (curChild < heapEnd) {
                if (curChild + 1 < heapEnd && heap[curChild] > heap[curChild + 1]) {
                    curChild++;
                }

                if (valueMove <= heap[curChild]) break;

                heap[curNode] = heap[curChild];
                curNode = curChild;
                curChild *= 2;
            }

            heap[curNode] = valueMove;
            return valueReturn;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        PqMinTop pqMinTop = new PqMinTop(100_000);

        while (n-- > 0) {
            int x = Integer.parseInt(br.readLine());

            if (x == 0) {
                sb.append(pqMinTop.pop()).append("\n");
            } else {
                pqMinTop.push(x);
            }
        }

        System.out.print(sb);
        br.close();
    }

}
