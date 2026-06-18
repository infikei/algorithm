// Solve 2026-06-18

class LC_3612 {
    public String processStr(String s) {
        char[] buf = new char[600000];
        int len = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == '#') {
                for (int j = 0; j < len; j++) {
                    buf[j + len] = buf[j];
                }

                len *= 2;
            } else if (c == '%') {
                for (int j = 0, k = len - 1; j < k; j++, k--) {
                    char tmp = buf[j];
                    buf[j] = buf[k];
                    buf[k] = tmp;
                }
            } else if (c == '*') {
                if (len > 0) {
                    len--;
                }
            } else {
                buf[len] = c;
                len++;
            }
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < len; i++) {
            sb.append(buf[i]);
        }

        return sb.toString();
    }
}
