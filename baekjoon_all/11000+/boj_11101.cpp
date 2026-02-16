// Solve 2026-02-15

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

void input_condition_value(unordered_map<string, int>& condition_value) {
    string s;
    cin >> s;

    stringstream ss(s);
    string w;

    while (getline(ss, w, ',')) {
        stringstream ww(w);
        string p1, p2;
        getline(ww, p1, ':');
        getline(ww, p2);

        condition_value[p1] = stoi(p2);
    }
}

void print_min_time(unordered_map<string, int>& condition_value) {
    string s;
    cin >> s;
    int mn = INF;

    stringstream ss(s);
    string w;

    while (getline(ss, w, '|')) {
        stringstream ww(w);
        string p;
        int mx = 0;

        while (getline(ww, p, '&')) {
            mx = max(mx, condition_value[p]);
        }

        mn = min(mn, mx);
    }

    cout << mn << '\n';
}

void solution() {
    unordered_map<string, int> condition_value;

    input_condition_value(condition_value);
    print_min_time(condition_value);
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        solution();
    }

    return 0;
}
