// Solve 2025-01-15

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

int get_mbti_dist(string a, string b) {
    int res = 0;

    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            res++;
        }
    }

    return res;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        map<string, int> mbti_cnt;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            mbti_cnt[s]++;
        }

        vector<string> mbti;

        for (auto it = mbti_cnt.begin(); it != mbti_cnt.end(); it++) {
            int iter = min(it->second, 3);

            while (iter-- > 0) {
                mbti.push_back(it->first);
            }
        }

        int ans = 1000;

        for (int i = 0; i < size(mbti); i++) {
            for (int j = i + 1; j < size(mbti); j++) {
                int res1 = get_mbti_dist(mbti[i], mbti[j]);

                for (int k = j + 1; k < size(mbti); k++) {
                    int res2 = res1 + get_mbti_dist(mbti[i], mbti[k]) + get_mbti_dist(mbti[j], mbti[k]);
                    ans = min(ans, res2);
                }
            }
        }

        println(ans);
    }

    return 0;
}
