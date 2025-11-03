// Solve 2022-08-30
// Update 2025-10-30

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

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        priority_queue<int> pq_maxtop;
        priority_queue<int, vector<int>, greater<int>> pq_mintop;
        map<int, int> cnt; // 저장한 수와 그 중복된 개수를 저장하는 map

        while (n-- > 0) {
            char cmd;
            int x;
            cin >> cmd >> x;

            if (cmd == 'I') {
                pq_maxtop.push(x);
                pq_mintop.push(x);
                cnt[x]++;
            }
            else if (x == 1) {
                while (!pq_maxtop.empty() && cnt[pq_maxtop.top()] == 0) {
                    pq_maxtop.pop();
                }

                if (!pq_maxtop.empty()) {
                    cnt[pq_maxtop.top()]--;
                    pq_maxtop.pop();
                }
            }
            else {
                while (!pq_mintop.empty() && cnt[pq_mintop.top()] == 0) {
                    pq_mintop.pop();
                }

                if (!pq_mintop.empty()) {
                    cnt[pq_mintop.top()]--;
                    pq_mintop.pop();
                }
            }
        }

        while (!pq_maxtop.empty() && cnt[pq_maxtop.top()] == 0) {
            pq_maxtop.pop();
        }

        while (!pq_mintop.empty() && cnt[pq_mintop.top()] == 0) {
            pq_mintop.pop();
        }

        if (pq_maxtop.empty()) {
            cout << "EMPTY" << '\n';
        }
        else {
            cout << pq_maxtop.top() << ' ' << pq_mintop.top() << '\n';
        }
    }

    return 0;
}
