#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    fastio;

    ll a, b;
    cin >> a >> b;
    ll gcd_a_b = gcd(a, b);

    for (int i = 0; i < gcd_a_b; i++) cout << '1';
    cout << '\n';

    return 0;
}