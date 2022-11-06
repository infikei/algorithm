#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int V, E, F; // V : 꼭짓점의 수, E : 모서리의 수, F : 면의 수
        cin >> V >> E;

        F = 2 - V + E; // 오일러의 다면체 공식
        cout << F << '\n';
    }

    return 0;
}