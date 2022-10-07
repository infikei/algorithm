#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    ll N, R;
    cin >> N >> R;

    ll ans = N - 1 + 2 * R;
    cout << ans << '\n';

    return 0;
}