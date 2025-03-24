// Solve 2023-03-30

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    stack<int> stck;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            answer.push_back(i);
            stck.push(n / i);
        }
    }

    if (answer.back() == stck.top()) {
        stck.pop();
    }
    while (!stck.empty()) {
        answer.push_back(stck.top());
        stck.pop();
    }

    return answer;
}
