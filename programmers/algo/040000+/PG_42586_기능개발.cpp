// Solve 2023-03-19
// Update 2025-04-16

#include <string>
#include <vector>

using namespace std;

int get_remaining_days(int progress, int speed) {
    int remaining = 100 - progress;

    return (remaining - 1) / speed + 1;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int n = progresses.size();
    vector<int> answer;
    int prev_remaining_days = get_remaining_days(progresses[0], speeds[0]);
    answer.push_back(1);

    for (int i = 1; i < n; i++) {
        int remaining_days = get_remaining_days(progresses[i], speeds[i]);
        if (prev_remaining_days >= remaining_days) {
            answer.back()++;
        }
        else {
            prev_remaining_days = remaining_days;
            answer.push_back(1);
        }
    }

    return answer;
}
