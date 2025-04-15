// Solve 2025-04-15

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

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

    for (string &word : words) {
        cin >> word;
    }

    sort(words.begin(), words.end(), Cmp());
    words.erase(unique(words.begin(), words.end()), words.end());

    for (string &word : words) {
        cout << word << '\n';
    }

    return 0;
}
