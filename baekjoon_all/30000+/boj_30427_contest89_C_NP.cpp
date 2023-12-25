// Solve 2023-10-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string message;
    getline(cin, message);

    unordered_set<string> hs;
    hs.insert("swi");

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string person;
        cin >> person;

        hs.insert(person);
    }

    string ans;

    if (hs.find("dongho") != hs.end()) {
        ans = "dongho";
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string person;
        cin >> person;

        hs.erase(person);
    }

    if (ans.empty() && SIZE(hs) == 1) {
        ans = *hs.begin();
    }

    if (ans.empty() && hs.find("bumin") != hs.end()) {
        ans = "bumin";
    }

    if (ans.empty() && hs.find("cake") != hs.end()) {
        ans = "cake";
    }

    if (ans.empty() && hs.find("lawyer") != hs.end()) {
        ans = "lawyer";
    }

    if (ans.empty()) {
        priority_queue<string, vector<string>, greater<string> > pq_mintop;

        for (auto it = hs.begin(); it != hs.end(); it++) {
            pq_mintop.push(*it);
        }

        if (pq_mintop.top() == "swi") {
            pq_mintop.pop();
        }

        ans = pq_mintop.top();
    }

    cout << ans << '\n';

    return 0;
}
