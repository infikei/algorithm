// Solve 2023-03-21

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int min_idx = 0, min_val = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < min_val) {
            min_idx = i;
            min_val = arr[i];
        }
    }

    vector<int> answer = arr;
    answer.erase(answer.begin() + min_idx);
    if (answer.empty()) {
        answer.push_back(-1);
    }

    return answer;
}
