#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ll = long long;

int main() {
    fastio;

    string S;
    int N;
    cin >> S >> N;

    ll cnt[3] = {0};
    for (int n = 0; n < N; n++) {
        string s0;
        cin >> s0;

        for (int i = 0; i < 3; i++) {
            if (S[i] == s0[0]) {
                cnt[i]++;
                break;
            }
        }
    }

    ll ans = 0;
    if (S[0] == S[1]) {
        if (S[1] == S[2]) {
            ans = cnt[0] * (cnt[0] - 1) / 2 * (cnt[0] - 2) / 3;
        }
        else {
            ans = cnt[0] * (cnt[0] - 1) / 2 * cnt[2];
        }
    }
    else {
        if (S[0] == S[2]) {
            ans = cnt[0] * (cnt[0] - 1) / 2 * cnt[1];
        }
        else if (S[1] == S[2]) {
            ans = cnt[1] * (cnt[1] - 1) / 2 * cnt[0];
        }
        else {
            ans = cnt[0] * cnt[1] * cnt[2];
        }
    }
    cout << ans << '\n';

    return 0;
}