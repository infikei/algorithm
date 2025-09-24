// Solve 2025-09-23

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

char get_new_score(string cur, string prev) {
    if (cur[0] == 'C') {
        return 'B';
    }
    if (cur == "B0" || cur == "B-") {
        if (prev[0] == 'A' || prev[0] == 'B') {
            return 'B';
        }
        return 'D';
    }
    if (cur == "A-" || cur == "B+") {
        if (prev[0] == 'A' || prev == "B+") {
            return 'D';
        }
        return 'P';
    }
    if (cur == "A0") {
        if (prev == "A+" || prev == "A0") {
            return 'P';
        }
        return 'E';
    }
    if (cur == "A+") {
        return 'E';
    }
    return '-';
}

int main() {
    FASTIO;

    int n;
    string s;
    cin >> n >> s;
    vector<string> scores;

    for (char c : s) {
        if (isupper(c)) {
            scores.push_back("");
            scores.back().push_back(c);
        }
        else {
            scores.back().push_back(c);
        }
    }

    for (string& w : scores) {
        if (size(w) == 1) {
            w.push_back('0');
        }
    }

    string new_scores;

    for (int i = 0; i < size(scores); i++) {
        char new_score = get_new_score(scores[i], (i == 0 ? "" : scores[i - 1]));
        new_scores.push_back(new_score);
    }

    cout << new_scores << '\n';
    return 0;
}
