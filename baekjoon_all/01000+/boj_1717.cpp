#include <iostream>
using namespace std;

int N, M;
int A[1000001];

int parent(int x) {
    if (A[x] == x) {
        return x;
    }

    A[x] = parent(A[x]);
    return A[x];
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        A[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;

        int a_parent = parent(a);
        int b_parent = parent(b);

        if (cmd == 0) {
            if (a_parent < b_parent) {
                A[b_parent] = a_parent;
            }
            else {
                A[a_parent] = b_parent;
            }
        }
        else {
            if (a_parent == b_parent) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}