// Solve 2023-03-28

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(string my_string) {
    unordered_set<char> hs;
    string answer = "";
    for (auto ch : my_string) {
        if (hs.find(ch) == hs.end()) {
            answer.push_back(ch);
            hs.insert(ch);
        }
    }

    return answer;
}
