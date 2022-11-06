#include <iostream>
#include <string>
using namespace std;

int S_arr[200001][26] = {0};

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string S;
    char ch;
    int Q, left, right;

    cin >> S;
    cin >> Q;

    for (int i = 0; i < S.length(); i++) {
        for (int j = 0; j < 26; j++) {
            S_arr[i + 1][j] = S_arr[i][j];
        }
        S_arr[i + 1][S[i] - 'a']++;
    }

    for (int q = 0; q < Q; q++) {
        cin >> ch >> left >> right;
        cout << S_arr[right + 1][ch - 'a'] - S_arr[left][ch - 'a'] << '\n';
    }

    return 0;
}