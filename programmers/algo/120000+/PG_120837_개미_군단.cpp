// Solve 2023-03-24

#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;

    answer += hp / 5;
    hp %= 5;
    answer += hp / 3;
    hp %= 3;
    answer += hp;

    return answer;
}
