// Solve 2025-04-16

class PG_72410_신규_아이디_추천 {

    boolean isLower(char ch) {
        return 'a' <= ch && ch <= 'z';
    }

    boolean isDigit(char ch) {
        return '0' <= ch && ch <= '9';
    }

    boolean isValidCharacter(char ch) {
        return isLower(ch) || isDigit(ch) || ch == '-' || ch == '_' || ch == '.';
    }

    String removeContinuousDot(String str) {
        StringBuilder sb = new StringBuilder();

        for (char ch : str.toCharArray()) {
            if (ch == '.' && sb.length() >= 1 && sb.charAt(sb.length() - 1) == '.') continue;

            sb.append(ch);
        }

        return sb.toString();
    }

    String removeBeginningDot(String str) {
        StringBuilder sb = new StringBuilder();
        int i_begin = 0;

        while (i_begin < str.length() && str.charAt(i_begin) == '.') {
            i_begin++;
        }

        for (int i = i_begin; i < str.length(); i++) {
            sb.append(str.charAt(i));
        }

        return sb.toString();
    }

    String removeEndingDot(String str) {
        StringBuilder sb = new StringBuilder();
        int i_end = str.length() - 1;

        while (i_end >= 0 && str.charAt(i_end) == '.') {
            i_end--;
        }

        for (int i = 0; i <= i_end; i++) {
            sb.append(str.charAt(i));
        }

        return sb.toString();
    }

    public String solution(String new_id) {
        // Step 1

        new_id = new_id.toLowerCase();

        // Step 2

        StringBuilder sb = new StringBuilder();

        for (char ch : new_id.toCharArray()) {
            if (isValidCharacter(ch)) {
                sb.append(ch);
            }
        }

        new_id = sb.toString();

        // Step 3

        new_id = removeContinuousDot(new_id);

        // Step 4

        new_id = removeBeginningDot(new_id);
        new_id = removeEndingDot(new_id);

        // Step 5

        if (new_id.isEmpty()) {
            new_id = "a";
        }

        // Step 6

        if (new_id.length() >= 16) {
            new_id = new_id.substring(0, 15);
            new_id = removeEndingDot(new_id);
        }

        // Step 7

        while (new_id.length() <= 2) {
            new_id += new_id.charAt(new_id.length() - 1);
        }

        return new_id;
    }

}
