// Solve 2023-03-21

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    for (auto num : numbers) {
        answer -= num;
    }

    return answer;
}
