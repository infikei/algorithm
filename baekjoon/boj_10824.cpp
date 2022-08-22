#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string A, B, C, D;
    cin >> A >> B >> C >> D;

    long long ans = stoll(A + B) + stoll(C + D);
    cout << ans << '\n';

    return 0;
}