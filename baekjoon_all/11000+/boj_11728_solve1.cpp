#include <iostream>
#include <algorithm>
using namespace std;

int N, M, NM;
int AB[2000000];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> M;
    NM = N + M;
    for (int i = 0; i < NM; i++) {
        cin >> AB[i];
    }

    sort(AB, AB + NM);

    for (int i = 0; i < NM; i++) {
        cout << AB[i] << ' ';
    }
    cout << '\n';

    return 0;
}