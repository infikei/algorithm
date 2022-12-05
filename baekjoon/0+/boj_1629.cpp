#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

ll A, B, C;

ll power(ll n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return A % C;
    }

    ll k = power(n / 2);
    if (n % 2 == 0) {
        return k * k % C;
    }
    else {
        return k * k % C * A % C;
    }
}

int main() {
    fastio;

    cin >> A >> B >> C;

    cout << power(B) << '\n';

    return 0;
}