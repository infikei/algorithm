// Solve 2023-09-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n, k;
int cards[10];
bool visited[10];
unordered_set<string> st;

void dfs(int depth = 0, string selected_cards = "") {
    if (depth == k) {
        st.insert(selected_cards);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        dfs(depth + 1, selected_cards + to_string(cards[i]));
        visited[i] = false;
    }
}

int main() {
    FASTIO;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        cards[i] = x;
    }

    dfs();

    cout << SIZE(st) << '\n';

    return 0;
}
