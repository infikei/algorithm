// Solve 2023-03-19

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int s_len = s.length();

    for (int i = 0; i < s_len; i++) {
        int same = 1, diff = 0;

        for (int j = i + 1; j < s_len; j++) {
            if (s[j] == s[i]) {
                same++;
            }
            else {
                diff++;
            }
            if (same == diff) {
                i = j;
                break;
            }
        }
        if (same != diff) {
            i = s_len;
        }

        answer++;
    }

    return answer;
}
