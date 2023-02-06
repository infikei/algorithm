#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ll = long long;

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    fastio;

    ll A, B;
    cin >> A >> B;

    cout << lcm(A, B) << '\n';

    return 0;
}