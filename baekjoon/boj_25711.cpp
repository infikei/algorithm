#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int N, Q;
int x_arr[200001];
int y_arr[200001];
double memo[200001]; // 거리의 누적 합
double memo2[200001]; // 거리 * 가중치의 누적 합

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> x_arr[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> y_arr[i];
    }

    for (int i = 2; i <= N; i++) {
        double d = sqrt(pow((ll)(x_arr[i] - x_arr[i - 1]), 2) + pow((ll)(y_arr[i] - y_arr[i - 1]), 2));
        memo[i] = memo[i - 1] + d;

        if (y_arr[i] > y_arr[i - 1]) {
            d *= 3;
        }
        else if (y_arr[i] == y_arr[i - 1]) {
            d *= 2;
        }
        memo2[i] = memo2[i - 1] + d;
    }

    for (int q = 0; q < Q; q++) {
        int a, b;
        cin >> a >> b;

        cout << fixed;
        cout.precision(9);

        if (a < b) {
            cout << memo2[b] - memo2[a] << '\n';
        }
        else {
            // 반대 방향에서는 오르막길이 내리막길로 바뀌고 내리막길이 오르막길이 된다.
            // 따라서 3배, 2배, 1배의 가중치가 각각 1배, 2배, 3배로 바뀌어야 하므로
            // memo 값의 4배에서 memo2의 값을 빼주면 값을 구할 수 있다.
            cout << (memo[a] - memo[b]) * 4 - (memo2[a] - memo2[b]) << '\n';
        }
    }

    return 0;
}