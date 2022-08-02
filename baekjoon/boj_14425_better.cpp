#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string strArr[10000];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, M, ans = 0;
    string strTemp;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> strArr[i];
    }
    sort(strArr, strArr + N);

    for (int i = 0; i < M; i++) {
        cin >> strTemp;
        if (binary_search(strArr, strArr + N, strTemp)) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}