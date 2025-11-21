// Solve 2025-11-20

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

int weight[128];
string species_name[26];
int cnt[128];

int main() {
    FASTIO;

    weight['B'] = 2;
    weight['C'] = 1;
    weight['M'] = 4;
    weight['W'] = 3;

    species_name['B' - 'A'] = "Bobcat";
    species_name['C' - 'A'] = "Coyote";
    species_name['M' - 'A'] = "Mountain Lion";
    species_name['W' - 'A'] = "Wolf";

    int n;
    cin >> n;

    while (n-- > 0) {
        memset(cnt, 0, sizeof cnt);
        string loc, s;
        cin >> loc >> s;

        for (char c : s) {
            cnt[c]++;
        }

        int mx = -1;
        char dominant = '?';

        for (char c : "BCMW") {
            int score = weight[c] * cnt[c];

            if (score > mx) {
                mx = score;
                dominant = c;
            }
            else if (score == mx) {
                dominant = '?';
            }
        }

        cout << loc << ": ";

        if (dominant == '?') {
            cout << "There is no dominant species" << '\n';
        }
        else {
            cout << "The " << species_name[dominant - 'A'] << " is the dominant species" << '\n';
        }
    }

    return 0;
}
