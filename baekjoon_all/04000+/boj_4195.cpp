// Solve 2023-02-16

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

const int MAX_SIZE = 200000;
unordered_map<string, int> hs;
int parent[MAX_SIZE + 1];
int cnt[MAX_SIZE + 1];

int get_parent(int k) {
    if (parent[k] == k) {
        return k;
    }

    parent[k] = get_parent(parent[k]);
    return parent[k];
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int f;
        cin >> f;

        hs.clear();

        for (int fi = 0; fi < f; fi++) {
            string user1, user2;
            cin >> user1 >> user2;

            int user1_int, user2_int;

            if (hs.find(user1) == hs.end()) {
                user1_int = SIZE(hs);
                hs[user1] = user1_int;
                parent[user1_int] = user1_int;
                cnt[user1_int] = 1;
            }
            else {
                user1_int = hs[user1];
            }
            if (hs.find(user2) == hs.end()) {
                user2_int = SIZE(hs);
                hs[user2] = user2_int;
                parent[user2_int] = user2_int;
                cnt[user2_int] = 1;
            }
            else {
                user2_int = hs[user2];
            }

            int parent_of_user1_int = get_parent(user1_int);
            int parent_of_user2_int = get_parent(user2_int);

            if (parent_of_user1_int != parent_of_user2_int) {
                parent[parent_of_user2_int] = parent_of_user1_int;
                cnt[parent_of_user1_int] += cnt[parent_of_user2_int];
            }
            cout << cnt[parent_of_user1_int] << '\n';
        }
    }

    return 0;
}