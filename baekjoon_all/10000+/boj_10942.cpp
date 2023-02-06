#include <iostream>
using namespace std;

int N, M;
int arr[2000];
bool memo[2000][2000];

void initialize_memo() {
    for (int i = 0; i < N; i++) {
        int b = i, e = i;

        while (b >= 0 && e < N) {
            if (arr[b] != arr[e]) {
                break;
            }
            memo[b][e] = true;
            b--;
            e++;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        int b = i, e = i + 1;

        while (b >= 0 && e < N) {
            if (arr[b] != arr[e]) {
                break;
            }
            memo[b][e] = true;
            b--;
            e++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    initialize_memo();

    cin >> M;

    for (int i = 0; i < M; i++) {
        int b, e;
        cin >> b >> e;
        if (memo[b - 1][e - 1]) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}