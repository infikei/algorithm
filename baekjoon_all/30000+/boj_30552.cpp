// Solve 2023-12-23

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

    vector<string> names;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        if (name == "Present!") {
            names.pop_back();
        }
        else {
            names.push_back(name);
        }
    }

    if (names.empty()) {
        cout << "No Absences\n";
    }
    else {
        for (string &name : names) {
            cout << name << '\n';
        }
    }

    return 0;
}
