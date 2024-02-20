// Solve 2024-02-20

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_20055 {

    static class Position {
        int durability;
        boolean robot;

        Position(int durability) {
            this.durability = durability;
            this.robot = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        Position[] conveyorBelt = new Position[n * 2];

        for (int i = 0; i < n * 2; i++) {
            conveyorBelt[i] = new Position(Integer.parseInt(st.nextToken()));
        }

        int conveyorBeltBegin = 0;
        int conveyorBeltEnd = n - 1;
        int curStage = 0;
        int zeroDurabilityCount = 0;

        while (true) {
            curStage++;

            if (--conveyorBeltEnd == -1) {
                conveyorBeltEnd = n * 2 - 1;
            }

            if (--conveyorBeltBegin == -1) {
                conveyorBeltBegin = n * 2 - 1;
            }

            conveyorBelt[conveyorBeltEnd].robot = false;
            int curPos = conveyorBeltEnd;

            while (curPos != conveyorBeltBegin) {
                int prevPos = curPos - 1;

                if (prevPos == -1) {
                    prevPos = n * 2 - 1;
                }

                if (conveyorBelt[prevPos].robot && !conveyorBelt[curPos].robot && conveyorBelt[curPos].durability > 0) {
                    conveyorBelt[prevPos].robot = false;
                    conveyorBelt[curPos].robot = true;

                    if (--conveyorBelt[curPos].durability == 0) {
                        zeroDurabilityCount++;
                    }
                }

                curPos = prevPos;
            }

            conveyorBelt[conveyorBeltEnd].robot = false;

            if (conveyorBelt[conveyorBeltBegin].durability > 0) {
                conveyorBelt[conveyorBeltBegin].robot = true;

                if (--conveyorBelt[conveyorBeltBegin].durability == 0) {
                    zeroDurabilityCount++;
                }
            }

            if (zeroDurabilityCount >= k) break;
        }

        System.out.println(curStage);
        br.close();
    }

}
