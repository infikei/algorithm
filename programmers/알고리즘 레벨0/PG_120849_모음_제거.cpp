// Solve 2023-03-27

#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    char rm[5] = { 'a', 'e', 'i', 'o', 'u' };
    for (auto ch : my_string) {
        bool check = true;
        for (int i = 0; i < 5; i++) {
            if (ch == rm[i]) {
                check = false;
                break;
            }
        }
        if (check) {
            answer.push_back(ch);
        }
    }

    return answer;
}
