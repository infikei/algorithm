// Solve 2023-03-24

#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    if (share > balls / 2) {
        share = balls - share;
    }

    long long answer_long = 1;
    for (int i = 1; i <= share; i++) {
        answer_long *= balls + 1 - i;
        answer_long /= i;
    }

    int answer = answer_long;

    return answer;
}
