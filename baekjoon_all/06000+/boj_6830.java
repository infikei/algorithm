// Solve 2023-10-19

// 백준에 제출할 때는 class 이름을 Main으로 설정해야 함.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_6830 {
    public static void main(String[] args) throws IOException {
        BufferedReader br;
        String minCity;
        int minTemperature;

        br = new BufferedReader(new InputStreamReader(System.in));
        minCity = "";
        minTemperature = 201;

        while (true) {
            StringTokenizer st;
            String city;
            int temperature;

            st = new StringTokenizer(br.readLine(), " ");
            city = st.nextToken();
            temperature = Integer.parseInt(st.nextToken());

            if (temperature < minTemperature) {
                minTemperature = temperature;
                minCity = city;
            }

            if (city.equals("Waterloo")) break;
        }

        System.out.println(minCity);

        br.close();
    }
}
