// Solve 2025-11-07

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

    string hhmm, am_or_pm;
    int dt;
    cin >> hhmm >> am_or_pm >> dt;

    stringstream ss(hhmm);
    string w;
    getline(ss, w, ':');
    int hh = stoi(w);
    getline(ss, w);
    int mm = stoi(w);

    if (am_or_pm == "PM" && hh < 12) {
        hh += 12;
    }
    else if (am_or_pm == "AM" && hh == 12) {
        hh = 0;
    }

    int t = hh * 60 + mm;
    t = (t - dt + 1440) % 1440;
    hh = t / 60;
    mm = t % 60;

    if (hh <= 11) {
        am_or_pm = "AM";

        if (hh == 0) hh = 12;
    }
    else {
        am_or_pm = "PM";

        if (hh >= 13) hh -= 12;
    }

    cout << hh << ':';
    SETW(2, '0'); cout << mm << ' ' << am_or_pm << '\n';
    return 0;
}
