#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ll = long long;

int main() {
    fastio;

    ll A, B;
    cin >> A >> B;

    if (A > B) {
        ll tmp = A;
        A = B;
        B = tmp;
    }

    if (A == B || A + 1 == B) {
        cout << 0 << '\n';
    }
    else {
        cout << B - A - 1 << '\n';
        for (ll i = A + 1; i < B; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}