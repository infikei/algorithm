// Solve 2025-06-06
// Update 2025-09-13

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

bool visited[26];

int main() {
    FASTIO;

    string w, s;
    cin >> w >> s;
    string lock;

    for (char c : w) {
        if (visited[c - 'A']) continue;

        visited[c - 'A'] = true;
        lock.push_back(c);
    }

    for (int i = 0; i < 26; i++) {
        if (!visited[i]) {
            lock.push_back('A' + i);
        }
    }

    for (char& c : s) {
        c = lock[c - 'A'];
    }

    cout << s << '\n';
    return 0;
}
