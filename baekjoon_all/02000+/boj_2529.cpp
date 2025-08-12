// Solve 2023-01-28
// Update 2025-08-11

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

int k;
char par[9];
int selected[10];
bool visited[10];

bool recur(int depth) {
    if (depth == k + 1) {
        return true;
    }

    int range_max = 9;
    int range_min = 0;

    if (depth >= 1) {
        if (par[depth - 1] == '>') {
            range_max = selected[depth - 1] - 1;
        }
        else {
            range_min = selected[depth - 1] + 1;
        }
    }

    for (int d = range_max; d >= range_min; d--) {
        if (visited[d]) continue;

        visited[d] = true;
        selected[depth] = d;
        if (recur(depth + 1)) return true;
        visited[d] = false;
    }

    return false;
}

bool recur2(int depth) {
    if (depth == k + 1) {
        return true;
    }

    int range_min = 0;
    int range_max = 9;

    if (depth >= 1) {
        if (par[depth - 1] == '>') {
            range_max = selected[depth - 1] - 1;
        }
        else {
            range_min = selected[depth - 1] + 1;
        }
    }

    for (int d = range_min; d <= range_max; d++) {
        if (visited[d]) continue;

        visited[d] = true;
        selected[depth] = d;
        if (recur2(depth + 1)) return true;
        visited[d] = false;
    }

    return false;
}

int main() {
    FASTIO;

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> par[i];
    }

    recur(0);
    for (int i = 0; i <= k; i++) cout << selected[i];
    cout << '\n';

    memset(visited, false, sizeof visited);
    recur2(0);
    for (int i = 0; i <= k; i++) cout << selected[i];
    cout << '\n';
    return 0;
}
