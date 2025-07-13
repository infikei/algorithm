// Solve 2025-04-15
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

struct Cmp{
    bool operator()(const string &a, const string &b) const {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> words(n);

    for (string& word : words) {
        cin >> word;
    }

    sort(words.begin(), words.end(), Cmp());
    words.erase(unique(words.begin(), words.end()), words.end());

    for (string& word : words) {
        cout << word << '\n';
    }

    return 0;
}
