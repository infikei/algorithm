// Solve 2025-10-05

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

vector<int> adj[400001]; // 인접 리스트
int diameter = 0; // 트리의 지름
int height[400001]; // 각 노드의 최대 높이 (루트가 1번 노드일 때 기준)
int cnt[400001]; // 각 노드에서 최대 높이가 나올 수 있는 가짓수
int parent[400001]; // 각 노드의 부모 노드

void dfs(int cur, int par) {
    parent[cur] = par;
    height[cur] = 0;
    cnt[cur] = 1;

    for (int nxt : adj[cur]) {
        if (nxt == par) continue;

        dfs(nxt, cur);

        diameter = max(diameter, height[cur] + height[nxt] + 1);

        if (height[nxt] + 1 > height[cur]) {
            height[cur] = height[nxt] + 1;
            cnt[cur] = cnt[nxt];
        }
        else if (height[nxt] + 1 == height[cur]) {
            cnt[cur] += cnt[nxt];
        }
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 터널을 가장 길게 하려면, 트리의 지름을 이루는 두 정점끼리 새로운 간선을 만들어줘야 함
    // 이에 따라 우선 트리의 지름을 구하면서, parent, height, cnt 배열 갱신
    dfs(1, -1);

    ll tunnel_cnt = 0;
    map<int, int> mp;

    for (int u = 1; u <= n; u++) {
        // u번 노드 아래의 두 branch가 트리의 지름을 이루는 가짓수 계산
        mp.clear();
        mp[0] = 1; // u번 노드 아래에 branch가 하나이고 그 branch 자체가 트리의 지름인 경우를 계산하기 위함

        for (int nxt : adj[u]) {
            if (nxt == parent[u]) continue;

            tunnel_cnt += (ll) cnt[nxt] * mp[diameter - (height[nxt] + 1)];
            mp[height[nxt] + 1] += cnt[nxt];
        }
    }

    cout << diameter + 1 << ' ' << tunnel_cnt << '\n';
    return 0;
}
