// Solve 2023-03-19

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;

    answer = num_list;
    reverse(answer.begin(), answer.end());

    return answer;
}
