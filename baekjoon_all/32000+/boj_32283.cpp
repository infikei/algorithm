// Solve 2025-12-02

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

struct Bin{
    string b;
    int cnt;
    string rb;

    Bin(string s) : b(s) {
        cnt = 0;

        for (char c : b) {
            if (c == '1') {
                cnt++;
            }
        }

        rb = b;
        reverse(rb.begin(), rb.end());
    }
};

void dfs(int depth, int n, string cur, vector<Bin>& v) {
    if (depth == n) {
        v.emplace_back(cur);
        return;
    }

    dfs(depth + 1, n, cur + '0', v);
    dfs(depth + 1, n, cur + '1', v);
}

int main() {
    FASTIO;

    int n;
    string s;
    cin >> n >> s;

    vector<Bin> v;
    dfs(0, n, "", v);

    auto cmp = [](Bin& a, Bin& b) {
        if (a.cnt != b.cnt) return a.cnt < b.cnt;
        return a.rb < b.rb;
    };

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < size(v); i++) {
        if (s == v[i].b) {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
