// Solve 2023-07-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    n += 56;
    n %= 60;

    string ans;
    ans.push_back('A' + (n % 12));
    ans.push_back('0' + (n % 10));
    cout << ans << '\n';

    return 0;
}
