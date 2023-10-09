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

    unordered_set<string> never_heard;

    for (int i = 0; i < n; i++) {
        string person;
        cin >> person;

        never_heard.insert(person);
    }

    vector<string> never_heard_and_never_seen;

    for (int i = 0; i < m; i++) {
        string person;
        cin >> person;

        if (never_heard.find(person) != never_heard.end()) {
            never_heard_and_never_seen.push_back(person);
        }
    }

    sort(never_heard_and_never_seen.begin(), never_heard_and_never_seen.end());

    cout << SIZE(never_heard_and_never_seen) << '\n';

    for (string &person : never_heard_and_never_seen) {
        cout << person << '\n';
    }

    return 0;
}
