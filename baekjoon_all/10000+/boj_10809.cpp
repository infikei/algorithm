// Solve 2022-06-05
// Update 2025-07-19

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

int visited[26];

int main() {
    FASTIO;

    memset(visited, -1, sizeof visited);
    string s;
    cin >> s;

    for (int i = 0; i < size(s); i++) {
        if (visited[s[i] - 'a'] == -1) {
            visited[s[i] - 'a'] = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << visited[i] << ' ';
    }

    cout << '\n';
    return 0;
}
