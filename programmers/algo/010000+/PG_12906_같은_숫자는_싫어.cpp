// Solve 2023-03-19

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    for (auto num : arr) {
        if (answer.empty() || num != answer.back()) {
            answer.push_back(num);
        }
    }

    return answer;
}
