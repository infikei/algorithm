// Solve 2025-04-16

class PG_60057_문자열_압축 {

    int getSizeOfCompressedString(String s, int len) {
        int result = 0;
        String prevWord = "";
        int repeatCnt = 0;

        for (int i = 0; i < s.length(); i += len) {
            String curWord = s.substring(i, Math.min(i + len, s.length()));

            if (curWord.equals(prevWord)) {
                repeatCnt++;
            } else {
                if (repeatCnt >= 2) {
                    result += Integer.toString(repeatCnt).length();
                }

                result += prevWord.length();
                prevWord = curWord;
                repeatCnt = 1;
            }
        }

        if (repeatCnt >= 2) {
            result += Integer.toString(repeatCnt).length();
        }

        result += prevWord.length();

        return result;
    }

    public int solution(String s) {
        int answer = s.length();

        for (int i = 1; i < s.length(); i++) {
            answer = Math.min(answer, getSizeOfCompressedString(s, i));
        }

        return answer;
    }

}
