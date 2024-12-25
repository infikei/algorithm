// Solve 2023-11-25

#include <string>
#include <vector>

using namespace std;

const int INF = 1e9;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int alp_target = alp;
    int cop_target = cop;

    for (vector<int> &problem : problems) {
        alp_target = max(alp_target, problem[0]);
        cop_target = max(cop_target, problem[1]);
    }

    vector<vector<int> > dp(alp_target + 1, vector<int>(cop_target + 1, INF));
    dp[alp][cop] = 0;

    for (int i = alp; i <= alp_target; i++) {
        for (int j = cop; j <= cop_target; j++) {
            int ni = min(i + 1, alp_target);
            dp[ni][j] = min(dp[ni][j], dp[i][j] + 1);

            int nj = min(j + 1, cop_target);
            dp[i][nj] = min(dp[i][nj], dp[i][j] + 1);

            for (vector<int> &problem : problems) {
                if (i < problem[0] || j < problem[1]) {
                    continue;
                }

                ni = min(i + problem[2], alp_target);
                nj = min(j + problem[3], cop_target);
                dp[ni][nj] = min(dp[ni][nj], dp[i][j] + problem[4]);
            }
        }
    }

    return dp[alp_target][cop_target];
}
