// Solve 2022-10-29
// Update 2023-10-10

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

    unordered_set<string> company;

    for (int i = 0; i < n; i++) {
        string name, log;
        cin >> name >> log;

        if (log == "enter") {
            company.insert(name);
        }
        else {
            company.erase(name);
        }
    }

    priority_queue<string> pq_maxtop;

    for (auto it = company.begin(); it != company.end(); it++) {
        pq_maxtop.push(*it);
    }

    while (!pq_maxtop.empty()) {
        cout << pq_maxtop.top() << '\n';
        pq_maxtop.pop();
    }

    return 0;
}
