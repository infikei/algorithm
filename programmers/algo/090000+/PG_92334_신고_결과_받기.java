// Solve 2025-05-23

import java.util.*;

class PG_92334_신고_결과_받기 {

    public int[] solution(String[] id_list, String[] report, int k) {
        Map<String, Set<String>> reporter = new TreeMap<>();
        Map<String, Set<String>> reportee = new TreeMap<>();

        for (String id : id_list) {
            reporter.put(id, new TreeSet<String>());
            reportee.put(id, new TreeSet<String>());
        }

        for (String repo : report) {
            StringTokenizer st = new StringTokenizer(repo);
            String id1 = st.nextToken();
            String id2 = st.nextToken();
            reporter.get(id1).add(id2);
            reportee.get(id2).add(id1);
        }

        int[] answer = new int[id_list.length];

        for (int i = 0; i < answer.length; i++) {
            String id = id_list[i];
            int mailCnt = 0;
            Iterator<String> iterator = reporter.get(id).iterator();

            while (iterator.hasNext()) {
                String id2 = iterator.next();

                if (reportee.get(id2).size() >= k) {
                    mailCnt++;
                }
            }

            answer[i] = mailCnt;
        }

        return answer;
    }

}
