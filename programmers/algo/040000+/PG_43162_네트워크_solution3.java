// Solve 2025-04-23

// Union Find 풀이

class PG_43162_네트워크_solution3 {

    static int[] parent;

    public int solution(int n, int[][] computers) {
        initParent(n);

        int componentCnt = n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (computers[i][j] == 1) {
                    if (unionParents(i, j)) {
                        componentCnt--;
                    }
                }
            }
        }

        return componentCnt;
    }

    void initParent(int n) {
        parent = new int[n];

        for (int u = 0; u < n; u++) {
            parent[u] = -1;
        }
    }

    int getParentOf(int u) {
        if (parent[u] < 0) return u;

        return parent[u] = getParentOf(parent[u]);
    }

    boolean unionParents(int u1, int u2) {
        u1 = getParentOf(u1);
        u2 = getParentOf(u2);

        if (u1 == u2) {
            return false;
        }

        if (parent[u1] < parent[u2]) {
            parent[u1] += parent[u2];
            parent[u2] = u1;
        } else {
            parent[u2] += parent[u1];
            parent[u1] = u2;
        }

        return true;
    }

}
