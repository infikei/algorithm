// Solve 2023-09-25
// Update 2025-07-20

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

void zigzag_nums(vector<int>& vec, deque<int>& dq) {
    if (!vec.empty()) {
        dq.push_back(vec[0]);
    }

    for (int i = 1; i < size(vec); i++) {
        if (abs(dq.front()) <= abs(dq.back())) {
            dq.push_back(vec[i]);
        }
        else {
            dq.push_front(vec[i]);
        }
    }

    if (!dq.empty() && dq.front() < dq.back()) {
        reverse(dq.begin(), dq.end());
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> vec_p;
    vector<int> vec_n;
    int zero_cnt = 0;

    while (n-- > 0) {
        int x;
        cin >> x;

        if (x > 0) vec_p.push_back(x);
        else if (x < 0) vec_n.push_back(x);
        else zero_cnt++;
    }

    sort(vec_p.begin(), vec_p.end(), greater<int>());
    deque<int> dq_p;
    zigzag_nums(vec_p, dq_p);

    sort(vec_n.begin(), vec_n.end());
    deque<int> dq_n;
    zigzag_nums(vec_n, dq_n);

    for (int& d : dq_p) {
        cout << d << ' ';
    }

    while (zero_cnt-- > 0) {
        cout << 0 << ' ';
    }

    for (int& d : dq_n) {
        cout << d << ' ';
    }

    cout << '\n';
    return 0;
}
