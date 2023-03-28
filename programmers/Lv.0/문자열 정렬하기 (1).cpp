// Solve 2023-03-27

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    for (auto ch : my_string) {
        if (isdigit(ch)) {
            answer.push_back(ch - '0');
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}
