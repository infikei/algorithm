#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, A[100], ans;

int main() {
    fastio;

    cin >> N;

    int A_max = 0, A_sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A_max = max(A_max, A[i]);
        A_sum += A[i];
    }

    ans = max(A_max, (A_sum - 1) / 2 + 1);

    if (ans > 1440) {
        ans = -1;
    }
    cout << ans << '\n';

    return 0;
}