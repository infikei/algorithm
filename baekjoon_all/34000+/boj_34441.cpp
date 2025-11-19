// Solve 2025-11-19

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

    string ski_name, hhmm, week_day;
    int bad_weather, recently_snowed, holiday;
    getline(cin, ski_name);
    cin >> hhmm >> week_day >> bad_weather >> recently_snowed >> holiday;

    stringstream ss(hhmm);
    string w;

    getline(ss, w, ':');
    int h = stoi(w);

    getline(ss, w);
    int m = stoi(w);

    int t = h * 60 + m;

    if (week_day == "sat" || week_day == "sun") {
        t *= 2;
    }

    if (bad_weather) {
        t *= 2;
    }

    if (recently_snowed) {
        t *= 3;
    }

    if (holiday) {
        t *= 3;
    }

    cout << t / 60 << ':';
    SETW(2, '0');
    cout << t % 60 << '\n';
    return 0;
}
