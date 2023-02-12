// Solve 2023-02-11

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

int n, m;
string s, t;
char aeiou[5] = { 'A', 'E', 'I', 'O', 'U' };

bool make_new_name() {
    t = s.substr(0, m - 3);

    int state = 0;
    for (int i = m - 3; i < n; i++) {
        if (state < 2) {
            if (s[i] == 'A') {
                t.push_back('A');
                state++;
            }
        }
        else if (state == 2) {
            bool is_not_aeiou = true;
            for (int j = 0; j < 5; j++) {
                if (s[i] == aeiou[j]) {
                    is_not_aeiou = false;
                    break;
                }
            }
            if (is_not_aeiou) {
                t.push_back(s[i]);
                state++;
            }
        }
        else break;
    }

    if (state < 3) return false;
    return true;
}

int main() {
    FASTIO;

    cin >> n >> m >> s;

    bool completed = make_new_name();
    if (completed) cout << "YES\n" << t << '\n';
    else cout << "NO\n";

    return 0;
}