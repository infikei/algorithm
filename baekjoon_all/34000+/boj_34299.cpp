// Solve 2025-11-08

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
    FASTIO;

    string s1, s2;
    cin >> s1 >> s2;

    int t1 = stoi(s1.substr(0, 2)) * 3600 + stoi(s1.substr(3, 2)) * 60 + stoi(s1.substr(6, 2));
    int t2 = stoi(s2.substr(0, 2)) * 3600 + stoi(s2.substr(3, 2)) * 60 + stoi(s2.substr(6, 2));

    int a = t2 / 43200 - t1 / 43200;
    int b = t2 / 3600 - t1 / 3600;
    int c = t2 / 60 - t1 / 60;

    cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}
