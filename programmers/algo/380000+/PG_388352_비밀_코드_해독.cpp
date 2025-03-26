// Solve 2025-02-08 (대회 Solve)
// Update 2025-03-25

#include <string>
#include <vector>

using namespace std;

int check(int n, vector<int> &nums, vector<vector<int>> &q, vector<int> &ans) {
    int m = q.size();

    for (int i = 0; i < m; i++) {
        vector<int> visited(n + 1);

        for (int j = 0; j < 5; j++) {
            visited[nums[j]]++;
        }

        for (int j = 0; j < 5; j++) {
            visited[q[i][j]]++;
        }

        int cnt = 0;

        for (int j = 1; j <= n; j++) {
            if (visited[j] == 2) {
                cnt++;
            }
        }

        if (cnt != ans[i]) return 0;
    }

    return 1;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<int> nums(5);

    for (nums[0] = 1; nums[0] <= n; nums[0]++) {
        for (nums[1] = nums[0] + 1; nums[1] <= n; nums[1]++) {
            for (nums[2] = nums[1] + 1; nums[2] <= n; nums[2]++) {
                for (nums[3] = nums[2] + 1; nums[3] <= n; nums[3]++) {
                    for (nums[4] = nums[3] + 1; nums[4] <= n; nums[4]++) {
                        answer += check(n, nums, q, ans);
                    }
                }
            }
        }
    }

    return answer;
}
