// Solve 2024-12-13

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

int n, k, ans;
string text[8];
bool selected[8];

vector<int> get_kmp_failure(string &p) {
    vector<int> f(size(p), 0);

    for (int i = 1, j = 0; i < size(p); i++) {
        while (j > 0 && p[i] != p[j]) {
            j = f[j - 1];
        }

        if (p[i] == p[j]) {
            j++;
            f[i] = j;
        }
    }

    return f;
}

int kmp(string &s, string &p) {
    vector<int> f = get_kmp_failure(p);
    int res = 0;

    for (int i = 0, j = 0; i < size(s); i++) {
        while (j > 0 && s[i] != p[j]) {
            j = f[j - 1];
        }

        if (s[i] == p[j]) {
            j++;

            if (j == size(p)) {
                res++;
                j = f[j - 1];
            }
        }
    }

    return res;
}

void dfs(int depth, string cur) {
    if (depth == n) {
        string cur2 = cur + cur;
        cur2.pop_back();

        if (kmp(cur2, cur) == k) {
            ans++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (selected[i]) continue;

        selected[i] = true;
        dfs(depth + 1, cur + text[i]);
        selected[i] = false;
    }
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> text[i];
    }

    cin >> k;

    dfs(0, "");

    println(ans);

    return 0;
}
