// Solve 2025-07-27

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class boj_1076 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        HashMap<String, Integer> map = new HashMap<>();
        map.put("black", 0);
        map.put("brown", 1);
        map.put("red", 2);
        map.put("orange", 3);
        map.put("yellow", 4);
        map.put("green", 5);
        map.put("blue", 6);
        map.put("violet", 7);
        map.put("grey", 8);
        map.put("white", 9);

        StringBuilder sb = new StringBuilder();
        sb.append(map.get(br.readLine()));
        sb.append(map.get(br.readLine()));
        int x = map.get(br.readLine());

        while (x-- > 0) {
            sb.append("0");
        }

        System.out.println(Long.parseLong(sb.toString()));
    }

}
