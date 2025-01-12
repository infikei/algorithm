// Solve 2025-01-12

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

struct Ruby{
    int x, y, val;

    Ruby(int x, int y, int val) : x(x), y(y), val(val) {}

    bool operator<(const Ruby &rhs) const {
        return val > rhs.val;
    }
};

int k;
int board[1000][1000];
vector<Ruby> vec;
int selected[5];

int recur(int depth, int begin_idx, int cur_sum) {
    if (depth == k) return cur_sum;

    int res = cur_sum;

    for (int i = begin_idx; i < size(vec); i++) {
        bool adjacent = false;

        for (int j = 0; j < depth; j++) {
            if (abs(vec[i].x - vec[selected[j]].x) + abs(vec[i].y - vec[selected[j]].y) == 1) {
                adjacent = true;
                break;
            }
        }

        if (adjacent) continue;

        selected[depth] = i;
        int nxt_sum = recur(depth + 1, i + 1, cur_sum + vec[i].val);
        res = max(res, nxt_sum);
    }

    return res;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m >> k;

    int kk = k * 5 - 4;

    priority_queue<Ruby> pq;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> board[x][y];
            pq.emplace(x, y, board[x][y]);
        }

        while (size(pq) > kk) {
            pq.pop();
        }
    }

    while (!pq.empty()) {
        vec.push_back(pq.top());
        pq.pop();
    }

    int ans = recur(0, 0, 0);
    println(ans);

    return 0;
}
