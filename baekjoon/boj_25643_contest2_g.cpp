#include <iostream>
#include <string>
using namespace std;

int N, M;
string s0, s1;
bool ans;

bool check() {
    for (int i = 1; i <= M; i++) {
        if (s0.substr(M - i, i) == s1.substr(0, i)) {
            return true;
        }
        if (s0.substr(0, i) == s1.substr(M - i, i)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> M;
    cin >> s0;
    ans = true;

    for (int i = 1; i < N; i++) {
        cin >> s1;
        if (!check()) {
            ans = false;
            break;
        }
        s0 = s1;
    }

    if (ans) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}