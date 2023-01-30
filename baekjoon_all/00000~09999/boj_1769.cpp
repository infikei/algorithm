#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

string X;
int cnt, ans;

void solve() {
    if ((int)X.length() == 1) {
        ans = stoi(X);
        return;
    }

    cnt++;
    int K = 0;
    for (auto a : X) {
        K += a - '0';
    }
    if (K < 10) {
        ans = K;
        return;
    }

    while (K > 0) {
        cnt++;
        int K_sum = 0;
        while (K > 0) {
            K_sum += K % 10;
            K /= 10;
        }
        if (K_sum < 10) {
            ans = K_sum;
            return;
        }
        K = K_sum;
    }
}

int main() {
    fastio;

    cin >> X;

    solve();

    cout << cnt << '\n';
    if (ans % 3 == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}