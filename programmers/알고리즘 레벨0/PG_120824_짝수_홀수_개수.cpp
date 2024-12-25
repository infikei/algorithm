// Solve 2023-03-19

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer(2);

    for (auto num : num_list) {
        if (num % 2 == 0) {
            answer[0]++;
        }
        else {
            answer[1]++;
        }
    }

    return answer;
}
