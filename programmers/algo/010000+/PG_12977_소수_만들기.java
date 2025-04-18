// Solve 2025-04-16

class PG_12977_소수_만들기 {

    boolean[] createSieveOfEratosthenes(int max) {
        boolean[] sieve = new boolean[max + 1];

        sieve[1] = true;

        for (int i = 2; i <= max; i++) {
            if (sieve[i]) continue;

            for (int j = i * 2; j <= max; j += i) {
                sieve[j] = true;
            }
        }

        return sieve;
    }

    public int solution(int[] nums) {
        boolean[] sieve = createSieveOfEratosthenes(3000);
        int cnt = 0;

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    int num = nums[i] + nums[j] + nums[k];

                    if (!sieve[num]) cnt++;
                }
            }
        }

        return cnt;
    }

}
