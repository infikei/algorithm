// Solve 2022-06-02
// Update 2023-02-22

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int a, b;
        cin >> a >> b;
        cout << (a + b) << '\n';
        // endl 대신 '\n'을 사용한다.
        // endl은 개행(줄바꿈) 뿐만 아니라 출력 버퍼를 비우는 역할까지 하는데,
        // endl을 사용하면 앞서 tie를 끊어주는 것의 효과를 볼 수가 없기 때문이다.
    }

    return 0;
}