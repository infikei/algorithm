// Solve 2023-03-29

#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";

    for (auto ch : my_string) {
        if (ch < 'a') {
            answer.push_back(ch - 'A' + 'a');
        }
        else {
            answer.push_back(ch - 'a' + 'A');
        }
    }

    return answer;
}
