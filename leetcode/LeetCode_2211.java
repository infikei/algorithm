// Solve 2025-12-05

class LeetCode_2211 {

    public int countCollisions(String directions) {
        int i = 0;
        int j = directions.length() - 1;

        while (i < directions.length() && directions.charAt(i) == 'L') {
            i++;
        }

        while (j >= 0 && directions.charAt(j) == 'R') {
            j--;
        }

        int cnt = 0;

        while (i <= j) {
            if (directions.charAt(i) != 'S') {
                cnt++;
            }

            i++;
        }

        return cnt;
    }

}
