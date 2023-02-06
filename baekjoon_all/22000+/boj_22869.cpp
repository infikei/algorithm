#include <iostream>
using namespace std;

int arr[5001];
bool possible[5001] = {false};
int N, K;
bool ans = false;

void input() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

bool check(int a, int b) {
    int need = (b - a) * (1 + max(arr[a] - arr[b], arr[b] - arr[a]));
    return need <= K;
}

void search(int now = 1) {
    if (now == N) {
        ans = true;
        return;
    }

    for (int next = now + 1; next <= N; next++) {
        if (!possible[next] && check(now, next)) {
            possible[next] = true;
            search(next);
            if (ans) {
                return;
            }
        }
    }
}

void print() {
    if (ans) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    possible[1] = true;
    search();

    print();

    return 0;
}