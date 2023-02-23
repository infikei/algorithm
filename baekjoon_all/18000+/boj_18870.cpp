// Solve 2023-02-23

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()); // 정렬이 이미 되어있는 상태에서 중복 제거
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    vector<int> v2 = v;
    sort(ALL(v2));
    UNIQUE(v2);

    unordered_map<int, int> hs;
    int i_end = SIZE(v2);
    for (int i = 0; i < i_end; i++) {
        hs[v2[i]] = i;
    }

    for (auto a : v) {
        cout << hs[a] << ' ';
    }
    cout << '\n';

    return 0;
}