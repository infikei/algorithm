#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, K;
    cin >> N >> K;

    stack<int> st_less, st_greater;

    for (int i = 1; i <= sqrt(N); i++) {
        if (N % i == 0) {
            st_less.push(i);
            st_greater.push(N / i);
        }
    }

    if (st_less.top() == st_greater.top()) {
        st_less.pop();
    }
    while (!st_less.empty()) {
        st_greater.push(st_less.top());
        st_less.pop();
    }

    if (K > (int)st_greater.size()) {
        cout << 0 << '\n';
    }
    else {
        while (K > 1) {
            K--;
            st_greater.pop();
        }
        cout << st_greater.top() << '\n';
    }

    return 0;
}