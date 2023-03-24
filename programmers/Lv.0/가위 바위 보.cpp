// Solve 2023-03-24

#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = "";

    for (char ch : rsp) {
        if (ch == '0') {
            answer.push_back('5');
        }
        else if (ch == '2') {
            answer.push_back('0');
        }
        else {
            answer.push_back('2');
        }
    }

    return answer;
}
