// Solve 2025-09-07

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

string vowels = "aeiou";

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        string w;
        cin >> w;
        int vowel_cnt = 0;

        for (char& c : w) {
            for (char& v : vowels) {
                if (c == v) {
                    vowel_cnt++;
                    break;
                }
            }
        }

        cout << "The number of vowels in " << w << " is " << vowel_cnt << "." << '\n';
    }

    return 0;
}
