// Solve 2026-06-04

class LC_3751 {

    public int getWaviness(int num) {
        int waviness = 0;
        char[] digits = Integer.toString(num).toCharArray();

        for (int i = 2; i < digits.length; i++) {
            if (digits[i - 2] < digits[i - 1] && digits[i - 1] > digits[i]) {
                waviness++;
            } else if (digits[i - 2] > digits[i - 1] && digits[i - 1] < digits[i]) {
                waviness++;
            }
        }

        return waviness;
    }

    public int totalWaviness(int num1, int num2) {
        int waviness = 0;

        for (int i = num1; i <= num2; i++) {
            waviness += getWaviness(i);
        }

        return waviness;
    }

}
