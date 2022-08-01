#include <iostream>
using namespace std;

long long arr[5001];
bool possible[5001];
int N;
long long ans;

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

bool check(long long K, int a, int b) {
    long long need = (b - a) * (1 + max(arr[a] - arr[b], arr[b] - arr[a]));
    return need <= K;
}

bool search(long long K, int now = 1) {
    if (now == N) {
        return true;
    }

    for (int next = now + 1; next <= N; next++) {
        if (!possible[next] && check(K, now, next)) {
            possible[next] = true;
            if (search(K, next)) {
                return true;
            }
        }
    }

    return false;
}

long long binary_search() {
    long long left = 0, right = 6000000000;
    long long mid = (left + right) / 2;
    long long result = right;

    while (left <= right) {
        possible[1] = true;
        for (int i = 2; i <= N; i++) {
            possible[i] = false;
        }

        if (search(mid)) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    ans = binary_search();

    cout << ans << '\n';

    return 0;
}