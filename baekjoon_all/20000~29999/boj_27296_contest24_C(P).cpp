#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

int main() {
    fastio;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        ll n;
        cin >> n;
        cout << (n < 2 ? "1 0\n" : "0 1\n");
    }

    return 0;
}