// Solve 2025-02-19

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

struct cmp{
    bool operator()(const pii &a, const pii &b) const {
        if (a.first != b.first) {
            return a.first > b.first;
        }

        return a.second < b.second;
    }
};

vector<pii> animals;

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int idx, l, r;
        cin >> idx >> l >> r;

        animals.emplace_back(l, r);
    }

    sort(animals.begin(), animals.end(), cmp());

    vector<int> memo;

    for (int i = 0; i < n; i++) {
        // 이전 활동영역과 완전히 일치하는 경우에는 skip한다.
        if (i >= 1 && animals[i - 1] == animals[i]) {
            continue;
        }

        // 선택한 수열에 같은 값이 여러 번 등장해도 되므로 lower_bound 대신 upper_bound를 사용한다.
        auto it = upper_bound(memo.begin(), memo.end(), animals[i].second);

        if (it == memo.end()) {
            memo.push_back(animals[i].second);
        }
        else {
            *it = animals[i].second;
        }
    }

    cout << size(memo) << '\n';

    return 0;
}
