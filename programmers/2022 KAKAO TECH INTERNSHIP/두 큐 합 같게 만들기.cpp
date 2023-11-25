// Solve 2023-11-25

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> que1;
    queue<int> que2;
    long sum_of_que1 = 0;
    long sum_of_que2 = 0;

    for (int x : queue1) {
        que1.push(x);
        sum_of_que1 += x;
    }

    for (int x : queue2) {
        que2.push(x);
        sum_of_que2 += x;
    }

    if ((sum_of_que1 + sum_of_que2) % 2 == 1) {
        return -1;
    }

    int iter = 0;
    int max_iter = (int)que1.size() * 4;

    while (iter < max_iter) {
        if (sum_of_que1 > sum_of_que2) {
            sum_of_que1 -= que1.front();
            que2.push(que1.front());
            que1.pop();
            sum_of_que2 += que2.back();
        }
        else if (sum_of_que1 < sum_of_que2) {
            sum_of_que2 -= que2.front();
            que1.push(que2.front());
            que2.pop();
            sum_of_que1 += que1.back();
        }
        else {
            return iter;
        }

        iter++;
    }

    return -1;
}
