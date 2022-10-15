#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    int ans = 0;
    int i = 1;
    int ii = 9;

    while (true) {
        if (N < ii) {
            ans += (N * i);
            break;
        }

        ans += (ii * i);
        N -= ii;
        i++;
        ii *= 10;
    }

    cout << ans << '\n';

    return 0;
}