// Solve 2023-03-19

#include <string>
#include <vector>

using namespace std;

int remaining_days(int progress, int speed) {
    int res = 0;

    progress = 100 - progress;
    res = progress / speed;
    if (progress % speed != 0) {
        res++;
    }

    return res;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int n = progresses.size();

    int prev = remaining_days(progresses[0], speeds[0]);
    answer.push_back(1);
    for (int i = 1; i < n; i++) {
        int cur = remaining_days(progresses[i], speeds[i]);
        if (prev < cur) {
            prev = cur;
            answer.push_back(1);
        }
        else {
            answer.back()++;
        }
    }

    return answer;
}
