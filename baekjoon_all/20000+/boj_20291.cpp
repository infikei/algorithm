// Solve 2023-09-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    map<string, int> mp_cnt;

    for (int i = 0; i < n; i++) {
        string file_name;
        cin >> file_name;

        stringstream ss(file_name);
        string file_ext;
        getline(ss, file_ext, '.');
        getline(ss, file_ext, '.');

        mp_cnt[file_ext]++;
    }

    for (auto it = mp_cnt.begin(); it != mp_cnt.end(); it++) {
        cout << it->first << ' ' << it->second << '\n';
    }

    return 0;
}
