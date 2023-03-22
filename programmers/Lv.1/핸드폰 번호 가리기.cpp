// Solve 2023-03-21

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = phone_number;

    for (int i = 0; i < (int)answer.length() - 4; i++) {
        answer[i] = '*';
    }

    return answer;
}
