// Solve 2025-12-16

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

struct Tree{
    int x, y, t;

    Tree(int x, int y, int t) : x(x), y(y), t(t) {
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;
    vector<Tree> trees;

    for (int i = 0; i < n; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        trees.emplace_back(x, y, t);
    }

    int mn = n;

    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            int low = trees[a].x;
            int high = trees[b].x;

            if (low > high) swap(low, high);

            for (int c = 0; c < n; c++) {
                for (int d = c; d < n; d++) {
                    int left = trees[c].y;
                    int right = trees[d].y;

                    if (left > right) swap(left, right);

                    int rect_len = (high - low + right - left) * 2;
                    int tree_cut_cnt = 0;
                    int tree_cut_len = 0;
                    priority_queue<int> pq;

                    for (int i = 0; i < n; i++) {
                        if (low <= trees[i].x && trees[i].x <= high && left <= trees[i].y && trees[i].y <= right) {
                            pq.push(trees[i].t);
                        }
                        else {
                            tree_cut_len += trees[i].t;
                            tree_cut_cnt++;
                        }
                    }

                    while (tree_cut_len < rect_len && !pq.empty()) {
                        tree_cut_cnt++;
                        tree_cut_len += pq.top();
                        pq.pop();
                    }

                    if (tree_cut_len >= rect_len) {
                        mn = min(mn, tree_cut_cnt);
                    }
                }
            }
        }
    }

    cout << mn << '\n';
    return 0;
}
