#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int p, q;
    cin >> p >> q;

    if (p <= 50 && q <= 10) cout << "White\n";
    else if (q > 30) cout << "Red\n";
    else cout << "Yellow\n";

    return 0;
}