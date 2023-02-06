#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    for (int n = 1; n <= N; n++) {
        int tri[3];
        for (int i = 0; i < 3; i++) {
            cin >> tri[i];
        }

        sort(tri, tri + 3);
        
        cout << "Scenario #" << n << ":\n";
        if (tri[0] * tri[0] + tri[1] * tri[1] == tri[2] * tri[2]) {
            cout << "yes\n\n";
        } else {
            cout << "no\n\n";
        }
    }

    return 0;
}