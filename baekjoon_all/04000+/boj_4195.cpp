// Solve 2023-02-16
// Update 2023-02-19

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
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_SIZE = 200000;
unordered_map<string, int> hs;
int parent[MAX_SIZE + 1]; // 양수이면 해당 노드의 부모 노드를 의미하며, 음수이면 -(해당 노드와 같은 집합인 노드들의 개수)를 의미한다.

int get_parent(int k) {
    if (parent[k] < 0) {
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
            string user1_str, user2_str;
            cin >> user1_str >> user2_str;

            int user1, user2;

            if (hs.find(user1_str) == hs.end()) {
                user1 = SIZE(hs);
                hs[user1_str] = user1;
                parent[user1] = -1;
            }
            else {
                user1 = hs[user1_str];
            }
            if (hs.find(user2_str) == hs.end()) {
                user2 = SIZE(hs);
                hs[user2_str] = user2;
                parent[user2] = -1;
            }
            else {
                user2 = hs[user2_str];
            }

            int parent_of_user1 = get_parent(user1);
            int parent_of_user2 = get_parent(user2);

            if (parent_of_user1 != parent_of_user2) {
                int cnt1 = parent[parent_of_user1];
                int cnt2 = parent[parent_of_user2];
                if (cnt1 < cnt2) {
                    parent[parent_of_user1] += cnt2;
                    parent[parent_of_user2] = parent_of_user1;
                    cout << -parent[parent_of_user1] << '\n';
                }
                else {
                    parent[parent_of_user2] += cnt1;
                    parent[parent_of_user1] = parent_of_user2;
                    cout << -parent[parent_of_user2] << '\n';
                }
            }
            else {
                cout << -parent[parent_of_user1] << '\n';
            }
        }
    }

    return 0;
}