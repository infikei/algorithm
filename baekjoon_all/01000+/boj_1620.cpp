// Solve 2022-06-03
// Update 2023-10-09

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<string> dogam_name(1, "");
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
