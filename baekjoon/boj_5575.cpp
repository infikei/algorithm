#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    for (int i = 0; i < 3; i++) {
        int h1, m1, s1, h2, m2, s2;
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        h2 -= h1;
        m2 -= m1;
        s2 -= s1;
        while (s2 < 0) {
            s2 += 60;
            m2--;
        }
        while (m2 < 0) {
            m2 += 60;
            h2--;
        }

        cout << h2 << ' ' << m2 << ' ' << s2 << '\n';
    }

    return 0;
}