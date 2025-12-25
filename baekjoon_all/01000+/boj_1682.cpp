// Solve 2025-12-24

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

set<string> visited;

string apply_command(string s, int cmd) {
    if (cmd == 0) {
        swap(s[0], s[7]);
        swap(s[1], s[6]);
        swap(s[2], s[5]);
        swap(s[3], s[4]);
    }
    else if (cmd == 1) {
        swap(s[3], s[2]);
        swap(s[2], s[1]);
        swap(s[1], s[0]);
        swap(s[4], s[5]);
        swap(s[5], s[6]);
        swap(s[6], s[7]);
    }
    else if (cmd == 2) {
        swap(s[1], s[2]);
        swap(s[2], s[5]);
        swap(s[5], s[6]);
    }
    else {
        swap(s[0], s[4]);
    }

    return s;
}

int main() {
    FASTIO;

    string s;

    for (int i = 0; i < 8; i++) {
        char c;
        cin >> c;
        s.push_back(c);
    }

    if (s == "12345678") {
        cout << 0 << '\n';
        return 0;
    }

    queue<string> que;
    que.push("12345678");
    visited.insert("12345678");
    int level = 0;

    while (!que.empty()) {
        level++;
        int iter = size(que);

        while (iter-- > 0) {
            string cur = que.front();
            que.pop();

            for (int cmd = 0; cmd < 4; cmd++) {
                string nxt = apply_command(cur, cmd);

                if (nxt == s) {
                    cout << level << '\n';
                    return 0;
                }

                if (visited.find(nxt) == visited.end()) {
                    visited.insert(nxt);
                    que.push(nxt);
                }
            }
        }
    }

    return 0;
}
