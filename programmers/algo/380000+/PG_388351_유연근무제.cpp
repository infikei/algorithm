// Solve 2025-02-08 (대회 Solve)
// Update 2025-03-25

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int n = schedules.size();

    for (int i = 0; i < n; i++) {
        int target_time = schedules[i] / 100 * 60 + schedules[i] % 100 + 10;
        int cnt = 0;

        for (int j = 0; j < 7; j++) {
            if ((startday + j - 1) % 7 >= 5) continue;

            int timelog = timelogs[i][j] / 100 * 60 + timelogs[i][j] % 100;

            if (timelog <= target_time) {
                cnt++;
            }
        }

        if (cnt == 5) {
            answer++;
        }
    }

    return answer;
}
