// Solve 2025-12-11

class LeetCode_3577 {

    public int countPermutations(int[] complexity) {
        final long MOD = 1000000007;

        long ret = 1;

        for (int i = 1; i < complexity.length; i++) {
            if (complexity[0] >= complexity[i]) {
                return 0;
            }

            ret = ret * i % MOD;
        }

        return (int) ret;
    }

}
