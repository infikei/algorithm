// Solve 2023-09-10
// Update 2025-07-13

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

struct CmpDone{
    bool operator()(const string& s1, const string& s2) const {
        if (size(s1) != size(s2)) return size(s1) < size(s2);
        return s1 < s2;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;
    cin.ignore();

    vector<int> boj;
    vector<string> done;
    regex re("boj.kr/([0-9]+)");
    smatch match;

    while (n-- > 0) {
        string s;
        getline(cin, s);

        if (regex_match(s, match, re)) {
            boj.push_back(stoi(match[1]));
        }
        else {
            done.push_back(s);
        }
    }

    sort(done.begin(), done.end(), CmpDone());
    sort(boj.begin(), boj.end());

    for (string& s : done) {
        cout << s << '\n';
    }

    for (int& x : boj) {
        cout << "boj.kr/" << x << '\n';
    }

    return 0;
}
