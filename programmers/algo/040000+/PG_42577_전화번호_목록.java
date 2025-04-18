// Solve 2025-04-16

import java.util.*;

class PG_42577_전화번호_목록 {

    public boolean solution(String[] phone_book) {
        HashSet<String> set = new HashSet<String>();

        for (String number : phone_book) {
            set.add(number);
        }

        for (String number : phone_book) {
            for (int len = 1; len < number.length(); len++) {
                String prefix = number.substring(0, len);

                if (set.contains(prefix)) {
                    return false;
                }
            }
        }

        return true;
    }

}
