// Solve 2026-06-06

class LC_3753 {

    static class Range {
        int left;
        int right;

        Range(int left, int right) {
            this.left = left;
            this.right = right;
        }
    }

    static class MemoData {
        long ascCount = 0;
        long ascWavinessSum = 0;
        long equalCount = 0;
        long equalWavinessSum = 0;
        long descCount = 0;
        long descWavinessSum = 0;
    }

    long getWaviness(long num) {
        long waviness = 0;
        char[] digits = Long.toString(num).toCharArray();

        for (int i = 2; i < digits.length; i++) {
            if (digits[i - 2] < digits[i - 1] && digits[i - 1] > digits[i]) {
                waviness++;
            } else if (digits[i - 2] > digits[i - 1] && digits[i - 1] < digits[i]) {
                waviness++;
            }
        }

        return waviness;
    }

    // 주어진 각 자리 숫자 범위를 만족하는 모든 수의 waviness의 총합 구하기 (dp 이용)
    long getTotalWavinessWithDigitRanges(Range[] digitRanges) {
        int nDigits = digitRanges.length;

        if (nDigits <= 2) return 0;

        MemoData[][] memo = new MemoData[15][10];

        for (int d = 0; d <= 9; d++) {
            memo[0][d] = new MemoData();

            if (digitRanges[0].left <= d && d <= digitRanges[0].right) {
                memo[0][d].equalCount = 1;
            }
        }

        for (int l = 1; l < nDigits; l++) {
            for (int d = 0; d <= 9; d++) {
                memo[l][d] = new MemoData();
            }

            for (int d = digitRanges[l].left; d <= digitRanges[l].right; d++) {
                for (int prvD = 0; prvD <= 9; prvD++) {
                    if (prvD < d) {
                        memo[l][d].ascCount += memo[l - 1][prvD].ascCount
                                + memo[l - 1][prvD].equalCount
                                + memo[l - 1][prvD].descCount;
                        memo[l][d].ascWavinessSum += memo[l - 1][prvD].ascWavinessSum
                                + memo[l - 1][prvD].equalWavinessSum
                                + memo[l - 1][prvD].descWavinessSum
                                + memo[l - 1][prvD].descCount;
                    } else if (prvD > d) {
                        memo[l][d].descCount += memo[l - 1][prvD].ascCount
                                + memo[l - 1][prvD].equalCount
                                + memo[l - 1][prvD].descCount;
                        memo[l][d].descWavinessSum += memo[l - 1][prvD].ascWavinessSum
                                + memo[l - 1][prvD].equalWavinessSum
                                + memo[l - 1][prvD].descWavinessSum
                                + memo[l - 1][prvD].ascCount;
                    } else {
                        memo[l][d].equalCount += memo[l - 1][prvD].ascCount
                                + memo[l - 1][prvD].equalCount
                                + memo[l - 1][prvD].descCount;
                        memo[l][d].equalWavinessSum += memo[l - 1][prvD].ascWavinessSum
                                + memo[l - 1][prvD].equalWavinessSum
                                + memo[l - 1][prvD].descWavinessSum;
                    }
                }
            }
        }

        long result = 0;

        for (int d = 0; d <= 9; d++) {
            result += memo[nDigits - 1][d].ascWavinessSum
                    + memo[nDigits - 1][d].equalWavinessSum
                    + memo[nDigits - 1][d].descWavinessSum;
        }

        return result;
    }

    // 1부터 num까지의 waviness 총합 구하기
    long getCumulativeWaviness(long num) {
        if (num <= 99) return 0;

        long result = 0;
        String numStr = Long.toString(num);
        int nDigits = numStr.length();

        for (int i = 1; i < nDigits; i++) {
            Range[] digitRanges = new Range[i];
            digitRanges[0] = new Range(1, 9);

            for (int j = 1; j < i; j++) {
                digitRanges[j] = new Range(0, 9);
            }

            result += getTotalWavinessWithDigitRanges(digitRanges);
        }

        for (int i = 0; i < nDigits; i++) {
            Range[] digitRanges = new Range[nDigits];

            for (int j = 0; j < i; j++) {
                digitRanges[j] = new Range(numStr.charAt(j) - '0',  numStr.charAt(j) - '0');
            }

            digitRanges[i] = new Range((i == 0 ? 1 : 0), (numStr.charAt(i) - '0') - 1);

            for (int j = i + 1; j < nDigits; j++) {
                digitRanges[j] = new Range(0, 9);
            }

            result += getTotalWavinessWithDigitRanges(digitRanges);
        }

        result += getWaviness(num);
        return result;
    }

    public long totalWaviness(long num1, long num2) {
        if (num2 - num1 <= 100) {
            long answer = 0;

            for (long i = num1; i <= num2; i++) {
                answer += getWaviness(i);
            }

            return answer;
        }

        if (num2 == 1000000000000000L) {
            num2--;
        }

        return getCumulativeWaviness(num2) - getCumulativeWaviness(num1 - 1);
    }

}
