#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, cnt, arr[501], prefix_sum[501];
bool isPrime[1000001];

void input() {
    cin >> N;
    for (int n = 1; n <= N; n++) {
        cin >> arr[n];
        prefix_sum[n] = prefix_sum[n - 1] + arr[n];
    }
}

void updateIsPrime() {
    for (int i = 2; i < 1000001; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i < 1000001; i++) {
        if (!isPrime[i]) {
            continue;
        }
        for (int j = i * 2; j < 1000001; j += i) {
            isPrime[j] = false;
        }
    }
}

void solve() {
    for (int len = 2; len <= N; len++) {
        if (!isPrime[len]) {
            continue;
        }
        for (int i = len; i <= N; i++) {
            if (isPrime[prefix_sum[i] - prefix_sum[i - len]]) {
                cnt++;
            }
        }
    }
}

int main() {
    fastio;

    updateIsPrime();

    input();

    solve();

    cout << cnt << '\n';

    return 0;
}