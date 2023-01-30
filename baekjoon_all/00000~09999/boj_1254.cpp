#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string S;
    cin >> S;

    string S_rev = S;
    reverse(S_rev.begin(), S_rev.end());

    int S_sz = S.length();
    int max_cnt = 0;

    for (int i = 1; i <= S_sz; i++) {
        if (S.substr(S_sz - i, i) == S_rev.substr(0, i)) {
            max_cnt = i;
        }
    }

    int ans = S_sz * 2 - max_cnt;
    cout << ans << '\n';

    return 0;
}