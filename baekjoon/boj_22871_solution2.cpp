#include <iostream>
using namespace std;

long long arr[5001], DP[5001][5001], ans;
int N;

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

long long power(int a, int b) {
    long long result = (b - a) * (1 + max(arr[a] - arr[b], arr[b] - arr[a]));
    return result;
}

long long solve(int now = 1, int next = N) {
    if (now == next) {
        return 0;
    }

    if (DP[now][next] > 0) {
        return DP[now][next];
    }

    long long result = power(now, next);
    for (int i = now + 1; i <= next - 1; i++) {
        result = min(result, max(solve(now, i), power(i, next)));
    }

    return DP[now][next] = result;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    cout << solve() << '\n';

    return 0;
}