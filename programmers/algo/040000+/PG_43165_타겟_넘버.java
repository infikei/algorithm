// Solve 2025-06-12

class PG_43165_타겟_넘버 {

    int dfs(int depth, int curNum, int[] numbers, int target) {
        if (depth == numbers.length) {
            return curNum == target ? 1 : 0;
        }

        return dfs(depth + 1, curNum + numbers[depth], numbers, target)
                + dfs(depth + 1, curNum - numbers[depth], numbers, target);
    }

    public int solution(int[] numbers, int target) {
        return dfs(0, 0, numbers, target);
    }

}
