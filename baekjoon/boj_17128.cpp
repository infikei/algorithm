#include <iostream>
using namespace std;

int N, Q;
int cow[200000];
int ans;

void ans_initialize() {
    int result = 0;
    for (int i = 0; i < N - 3; i++) {
        result += (cow[i] * cow[i + 1] * cow[i + 2] * cow[i + 3]);
    }
    result += (cow[N - 3] * cow[N - 2] * cow[N - 1] * cow[0]);
    result += (cow[N - 2] * cow[N - 1] * cow[0] * cow[1]);
    result += (cow[N - 1] * cow[0] * cow[1] * cow[2]);

    ans = result;
}

void ans_update(int idx) {
    int part = 0;
    for (int i = idx - 3; i <= idx; i++) {
        if (i >= 0 && i < N - 3) {
            part += (cow[i] * cow[i + 1] * cow[i + 2] * cow[i + 3]);
        }
        else if (i == -3 || i == N - 3) {
            part += (cow[N - 3] * cow[N - 2] * cow[N - 1] * cow[0]);
        }
        else if (i == -2 || i == N - 2) {
            part += (cow[N - 2] * cow[N - 1] * cow[0] * cow[1]);
        }
        else {
            part += (cow[N - 1] * cow[0] * cow[1] * cow[2]);
        }
    }

    ans = ans - 2 * part;
    cow[idx] *= -1;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        cin >> cow[i];
    }

    ans_initialize();

    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        ans_update(x - 1);
        cout << ans << '\n';
    }

    return 0;
}