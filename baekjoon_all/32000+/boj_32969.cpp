// Solve 2025-09-06

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

string keywords[7] = {"social", "history", "language", "literacy", "bigdata", "public", "society"};

int main() {
    FASTIO;

    vector<string> words;
    string s;
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    for (int i = 0; i < size(s); i++) {
        for (int j = 0; j < 4; j++) {
            if (i + size(keywords[j]) <= size(s) && s.substr(i, size(keywords[j])) == keywords[j]) {
                cout << "digital humanities" << '\n';
                return 0;
            }
        }

        for (int j = 4; j < 7; j++) {
            if (i + size(keywords[j]) <= size(s) && s.substr(i, size(keywords[j])) == keywords[j]) {
                cout << "public bigdata" << '\n';
                return 0;
            }
        }
    }

    return 0;
}
