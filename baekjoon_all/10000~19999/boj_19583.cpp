#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> hs;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    // 시각 형식이 5글자로 통일되어있으므로 int 자료형으로 변환할 필요가 없다.
    string S, E, Q;
    cin >> S >> E >> Q;

    string chat_time, chat_nickname;
    int cnt = 0;

    while (cin >> chat_time) {
        cin >> chat_nickname;

        if (chat_time <= S) {
            hs[chat_nickname] = false;
        }
        else if (E <= chat_time && chat_time <= Q) {
            if (hs.find(chat_nickname) != hs.end() && !hs[chat_nickname]) {
                hs[chat_nickname] = true;
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}