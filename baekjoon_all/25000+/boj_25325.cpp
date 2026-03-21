// Solve 2026-03-12

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

string name[100];
unordered_map<string, int> cnt;

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name[i];
        cnt[name[i]] = 0;
    }

    cin.ignore();

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        stringstream ss(s);
        string w;

        while (ss >> w) {
            cnt[w]++;
        }
    }

    vector<pair<int, string>> vec;

    for (int i = 0; i < n; i++) {
        vec.emplace_back(-cnt[name[i]], name[i]);
    }

    sort(vec.begin(), vec.end());

    for (auto a : vec) {
        cout << a.second << ' ' << -a.first << '\n';
    }

    return 0;
}
