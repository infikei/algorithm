// Solve 2023-03-28

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    for (auto s : strlist) {
        answer.push_back(s.length());
    }

    return answer;
}
