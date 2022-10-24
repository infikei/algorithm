#include <iostream>
using namespace std;

int N;
int cnt[2];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    if (cnt[0] > cnt[1]) {
        cout << "Junhee is not cute!\n";
    }
    else {
        cout << "Junhee is cute!\n";
    }

    return 0;
}