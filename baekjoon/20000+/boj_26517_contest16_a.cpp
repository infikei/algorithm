#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

int main() {
    fastio;

    ll k, a, b, c, d;

    cin >> k >> a >> b >> c >> d;

    if (a * k + b == c * k + d) cout << "Yes " << a * k + b << '\n';
    else cout << "No\n";

    return 0;
}