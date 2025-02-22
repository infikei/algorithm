// Solve 2022-06-03
// Update 2025-02-21

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

    int n, m;
    cin >> n >> m;

    vector<string> dogam_name;
    dogam_name.push_back("");
    unordered_map<string, int> dogam_idx;

    for (int i = 1; i <= n; i++) {
        string pokemon_name;
        cin >> pokemon_name;

        dogam_name.push_back(pokemon_name);
        dogam_idx[pokemon_name] = i;
    }

    for (int i = 0; i < m; i++) {
        string query;
        cin >> query;

        if (query[0] >= '0' && query[0] <= '9') {
            cout << dogam_name[stoi(query)] << '\n';
        }
        else {
            cout << dogam_idx[query] << '\n';
        }
    }

    return 0;
}
