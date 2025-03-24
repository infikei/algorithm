// Solve 2023-08-14

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names) {
    vector<string> answer;

    for (int i = 0, ie = (int)names.size(); i < ie; i += 5) {
        answer.push_back(names[i]);
    }

    return answer;
}
