#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, M;
    cin >> N >> M;

    if (M <= 2) {
        cout << "NEWBIE!\n";
    }
    else if (M <= N) {
        cout << "OLDBIE!\n";
    }
    else {
        cout << "TLE!\n";
    }

    return 0;
}