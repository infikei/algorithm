// Solve 2023-03-21

#include <string>
#include <algorithm>

using namespace std;

bool solution(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    int cnt[2] = { 0 };

    for (auto ch : s) {
        if (ch == 'p') {
            cnt[0]++;
        }
        else if (ch == 'y') {
            cnt[1]++;
        }
    }

    bool answer = true;
    if (cnt[0] != cnt[1]) {
        answer = false;
    }

    return answer;
}
