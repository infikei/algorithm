// Solve 2026-06-13

class LC_3838 {

    public String mapWordWeights(String[] words, int[] weights) {
        StringBuilder sb =  new StringBuilder();

        for (String word : words) {
            int wordWeight = 0;

            for (int i = 0; i < word.length(); i++) {
                wordWeight += weights[word.charAt(i) - 'a'];
            }

            wordWeight = 25 - wordWeight % 26;
            sb.append((char) ('a' + wordWeight));
        }

        return sb.toString();
    }

}
