// Solve 2023-03-30

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;

    unordered_map<string, int> hs;
    hs["zero"] = 0;
    hs["one"] = 1;
    hs["two"] = 2;
    hs["three"] = 3;
    hs["four"] = 4;
    hs["five"] = 5;
    hs["six"] = 6;
    hs["seven"] = 7;
    hs["eight"] = 8;
    hs["nine"] = 9;

    int i = 0;
    while (i < numbers.length()) {
        answer *= 10;
        for (auto it = hs.begin(); it != hs.end(); it++) {
            string s = it->first;
            if ((int)numbers.length() - i < (int)s.length()) {
                continue;
            }
            if (numbers.substr(i, (int)s.length()) == s) {
                answer += hs[s];
                i += s.length();
                break;
            }
        }
    }

    return answer;
}
