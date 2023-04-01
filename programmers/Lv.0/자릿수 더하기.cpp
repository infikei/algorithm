// Solve 2023-04-01

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    string n_str = to_string(n);
    int answer = 0;

    for (auto ch : n_str) {
        answer += ch - '0';
    }

    return answer;
}
