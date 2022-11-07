#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ll = long long;

int N, B, C;
ll cnt;
int A[1000000];

int main() {
    fastio;

    cin >> N;
    for (int n = 0; n < N; n++) {
        cin >> A[n];
    }
    cin >> B >> C;

    cnt = (ll)N;

    for (int n = 0; n < N; n++) {
        if (A[n] > B) {
            cnt += ((ll)A[n] - B - 1) / C + 1;
        }
    }

    cout << cnt << '\n';

    return 0;
}