// Solve 2023-03-21

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer(2);

    answer[0] = money / 5500;
    answer[1] = money % 5500;

    return answer;
}
