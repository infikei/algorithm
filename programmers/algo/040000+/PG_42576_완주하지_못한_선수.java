// Solve 2025-04-16

import java.util.*;

class PG_42576_완주하지_못한_선수 {

    public String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> counter = new HashMap<String, Integer>();

        for (String p : participant) {
            counter.put(p, counter.getOrDefault(p, 0) + 1);
        }

        for (String p : completion) {
            counter.put(p, counter.get(p) - 1);
        }

        for (String p : participant) {
            if (counter.get(p) != 0) {
                return p;
            }
        }

        return "";
    }

}
