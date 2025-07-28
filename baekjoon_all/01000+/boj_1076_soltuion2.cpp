// Solve 2022-06-17
// Update 2025-07-27

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

    unordered_map<string, int> mp;
    mp["black"] = 0;
    mp["brown"] = 1;
    mp["red"] = 2;
    mp["orange"] = 3;
    mp["yellow"] = 4;
    mp["green"] = 5;
    mp["blue"] = 6;
    mp["violet"] = 7;
    mp["grey"] = 8;
    mp["white"] = 9;

    string color;
    cin >> color;
    int a = mp[color];
    cin >> color;
    int b = mp[color];
    cin >> color;
    int c = mp[color];

    string val;
    val.push_back('0' + a);
    val.push_back('0' + b);

    while (c-- > 0) {
        val.push_back('0');
    }

    cout << stoll(val) << '\n';
    return 0;
}
