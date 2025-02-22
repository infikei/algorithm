// Solve 2025-02-21

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class boj_1816 {

    static ArrayList<Integer> findPrimes() {
        ArrayList<Integer> primes = new ArrayList<Integer>();
        boolean[] sieve = new boolean[1000000];

        for (int i = 2; i < 1000000; i++) {
            if (sieve[i]) continue;

            primes.add(i);

            for (int j = i * 2; j < 1000000; j += i) {
                sieve[j] = true;
            }
        }

        return primes;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer> primes = findPrimes();

        for (int i = 0; i < n; i++) {
            long s = Long.parseLong(br.readLine());
            boolean dividedByPrime = false;

            for (int p : primes) {
                if (s % p == 0) {
                    dividedByPrime = true;
                    break;
                }
            }

            if (dividedByPrime) {
                sb.append("NO\n");
            } else {
                sb.append("YES\n");
            }
        }

        System.out.println(sb);
    }

}
