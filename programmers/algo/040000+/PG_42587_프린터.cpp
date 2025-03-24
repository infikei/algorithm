// Solve 2023-03-19

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    int n = priorities.size();

    queue<pair<int, int> > q;
    priority_queue<int> pq_maxtop;
    for (int i = 0; i < n; i++) {
        q.push({ i, priorities[i] });
        pq_maxtop.push(priorities[i]);
    }

    while (!q.empty()) {
        if (q.front().second == pq_maxtop.top()) {
            answer++;
            if (q.front().first == location) {
                break;
            }
            q.pop();
            pq_maxtop.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }

    return answer;
}
