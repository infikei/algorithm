// Solve 2023-03-30

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int abc[26] = { 0 };
    for (auto ch : s) {
        abc[ch - 'a']++;
    }

    string answer = "";
    for (int i = 0; i < 26; i++) {
        if (abc[i] == 1) {
            answer.push_back('a' + i);
        }
    }

    return answer;
}
