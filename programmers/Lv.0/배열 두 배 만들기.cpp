// Solve 2023-03-19

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (auto num : numbers) {
        answer.push_back(num * 2);
    }

    return answer;
}
