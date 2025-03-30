// Solve 2025-03-29

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    unordered_map<string, int> hs;

    for (int i = 1; i <= n; i++) {
        string container_name;
        cin >> container_name;

        hs[container_name] = i;
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        string container_name;
        cin >> container_name;

        hs[container_name] += 10000000;
    }

    vector<pair<int, string>> vec;

    for (auto it = hs.begin(); it != hs.end(); it++) {
        vec.emplace_back(it->second, it->first);
    }

    sort(vec.begin(), vec.end());

    for (auto it = vec.rbegin(); it != vec.rend(); it++) {
        cout << it->second << '\n';
    }

    return 0;
}
