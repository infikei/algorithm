#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    string s;
    cin >> s;
    int ans = s.length() + 2;
    for (auto a : s) {
        if (a == '_') {
            ans += 5;
        }
    }
    cout << ans << '\n';

    return 0;
}