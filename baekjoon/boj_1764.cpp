#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> hs;
string strArr[500000];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, M, K = 0;
    cin >> N >> M;

    string strTemp;
    for (int i = 0; i < N; i++) {
        cin >> strTemp;
        hs[strTemp] = 1;
    }
    for (int i = 0; i < M; i++) {
        cin >> strTemp;
        if (hs.find(strTemp) != hs.end()) {
            strArr[K] = strTemp;
            K++;
        }
    }
    sort(strArr, strArr + K);
    cout << K << '\n';
    for (int i = 0; i < K; i++) {
        cout << strArr[i] << '\n';
    }

    return 0;
}