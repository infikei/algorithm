// Solve 2024-02-12

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 한다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class boj_2870 {

    static String convertToIntegerFormat(String s) {
        int i = 0;

        while (i < s.length() - 1 && s.charAt(i) == '0') {
            i++;
        }

        return s.substring(i);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<String> numbers = new ArrayList<String>();

        while (n-- > 0) {
            String line = br.readLine();
            StringBuilder curNum = new StringBuilder();

            for (int i = 0; i < line.length(); i++) {
                char c = line.charAt(i);

                if (c >= '0' && c <= '9') {
                    curNum.append(c);
                } else {
                    if (!curNum.toString().isEmpty()) {
                        numbers.add(convertToIntegerFormat(curNum.toString()));
                        curNum = new StringBuilder();
                    }
                }
            }

            if (!curNum.toString().isEmpty()) {
                numbers.add(convertToIntegerFormat(curNum.toString()));
            }
        }

        Collections.sort(numbers, new Comparator<String>() {

            @Override
            public int compare(String o1, String o2) {
                if (o1.length() != o2.length()) return o1.length() - o2.length();
                return o1.compareTo(o2);
            }

        });

        StringBuilder sb = new StringBuilder();

        for (String num : numbers) {
            sb.append(num).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

}
