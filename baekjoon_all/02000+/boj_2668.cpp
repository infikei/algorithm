// Solve 2025-02-10

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

int arr[101];
bool visited[101];

void init_visited(int n) {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> ans;

    for (int u = 1; u <= n; u++) {
        init_visited(n);

        int nu = arr[u];
        visited[nu] = true;

        while (nu != u && !visited[arr[nu]]) {
            nu = arr[nu];
            visited[nu] = true;
        }

        if (nu == u) {
            ans.push_back(u);
        }
    }

    println(size(ans));

    for (int &a : ans) {
        println(a);
    }

    return 0;
}
