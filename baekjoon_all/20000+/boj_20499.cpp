// Solve 2022-11-01
// Update 2023-08-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string kda;
    cin >> kda;

    stringstream ss(kda);
    string w;
    int kda_int[3];

    for (int i = 0; i < 3; i++) {
        getline(ss, w, '/');
        kda_int[i] = stoi(w);
    }

    if (kda_int[1] == 0 || kda_int[0] + kda_int[2] < kda_int[1]) {
        cout << "hasu\n";
    }
    else {
        cout << "gosu\n";
    }

    return 0;
}
