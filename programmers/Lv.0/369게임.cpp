// Solve 2023-03-29

#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    string order_str = to_string(order);
    int answer = 0;
    for (auto ch : order_str) {
        if (ch == '3' || ch == '6' || ch == '9') {
            answer++;
        }
    }

    return answer;
}
