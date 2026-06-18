// Solve 2026-06-18

class LC_3614 {

    public char processStr(String s, long k) {
        long len = 0L;
        boolean[] invalid = new boolean[s.length()];

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == '*') {
                if (len > 0) {
                    len--;
                } else {
                    invalid[i] = true;
                }
            } else if (c == '#') {
                len *= 2;
            } else if (c != '%') {
                len++;
            }
        }

        if (k >= len) {
            return '.';
        }

        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);

            if (c == '*') {
                if (!invalid[i]) {
                    len++;
                }
            } else if (c == '#') {
                len /= 2;
                k %= len;
            } else if (c == '%') {
                k = len - 1 - k;
            } else {
                len--;

                if (k >= len) {
                    return c;
                }
            }
        }

        return '.';
    }

}
