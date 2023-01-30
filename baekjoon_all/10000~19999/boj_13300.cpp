#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, K, ans;
int arr[2][6];

int main() {
    fastio;

    cin >> N >> K;
    for (int n = 0; n < N; n++) {
        int S, Y;
        cin >> S >> Y;
        arr[S][Y - 1]++;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            ans += (arr[i][j] + K - 1) / K;
        }
    }

    cout << ans << '\n';

    return 0;
}