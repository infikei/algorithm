#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int k, x;
    cin >> k;

    stack<int> s;

    for (int i = 0; i < k; i++) {
        cin >> x;
        if (x == 0)
            s.pop();
        else
            s.push(x);
    }

    int ans = 0;
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }

    cout << ans << '\n';

    return 0;
}