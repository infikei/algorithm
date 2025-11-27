// Solve 2022-06-06
// Update 2025-11-27

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

void solution() {
    string cmds, nums;
    int n;
    cin >> cmds >> n >> nums;

    deque<int> dq;
    string tmp;

    for (char ch : nums) {
        if (isdigit(ch)) {
            tmp += ch;
        }
        else {
            if (!tmp.empty()) {
                dq.push_back(stoi(tmp));
                tmp = "";
            }
        }
    }

    bool reversed = false;

    for (char cmd : cmds) {
        if (cmd == 'R') {
            reversed = !reversed;
            continue;
        }

        if (dq.empty()) {
            cout << "error" << '\n';
            return;
        }

        if (reversed) {
            dq.pop_back();
        }
        else {
            dq.pop_front();
        }
    }

    cout << '[';

    if (reversed) {
        for (int i = size(dq) - 1; i >= 0; i--) {
            cout << dq[i];

            if (i > 0) cout << ',';
        }
    }
    else {
        for (int i = 0; i < size(dq); i++) {
            cout << dq[i];

            if (i < size(dq) - 1) cout << ',';
        }
    }

    cout << "]\n";
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        solution();
    }

    return 0;
}
