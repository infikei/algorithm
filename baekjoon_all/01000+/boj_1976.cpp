// Solve 2023-02-14

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_N = 200;
int n, m, parent[MAX_N + 1];
bool ans;

int get_parent(int k) {
    if (parent[k] == k) {
        return k;
    }

    parent[k] = get_parent(parent[k]);
    return parent[k];
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int from = 1; from <= n; from++) {
        for (int to = 1; to <= n; to++) {
            int x;
            cin >> x;
            if (x == 1) {
                parent[get_parent(to)] = get_parent(from);
            }
        }
    }

    ans = true;
    int t0;
    cin >> t0;
    int pt0 = get_parent(t0);
    for (int i = 1; i < m; i++) {
        int t;
        cin >> t;
        if (get_parent(t) != pt0) {
            ans = false;
            // 남은 입력 모두 받아주고 break하기
            for (i++; i < m; i++) {
                cin >> t;
            }
            break;
        }
    }

    if (ans) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}