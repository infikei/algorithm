#include <iostream>
#include <string>
using namespace std;

int N, M;
string S[10];
string S2[10];

void input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> S2[i];
    }
}

bool solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] != S2[i][j * 2] || S[i][j] != S2[i][j * 2 + 1]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    if (solve()) {
        cout << "Eyfa\n";
    }
    else {
        cout << "Not Eyfa\n";
    }

    return 0;
}