// Solve 2023-03-30

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

int main() {
    FASTIO;

    int s[2];
    bool check[2];

    cin >> s[0] >> s[1];

    for (int si = 0; si < 2; si++) {
        check[si] = true;

        for (int i = 0; i < s[si]; i++) {
            int tc_ans, my_ans;
            cin >> tc_ans >> my_ans;
            if (tc_ans != my_ans) {
                check[si] = false;
                for (; i < s[si]; i++) {
                    cin >> tc_ans >> my_ans; // 이후 입력들을 모두 받아주고 break
                }
                break;
            }
        }
    }

    if (!check[0]) {
        cout << "Wrong Answer\n";
    }
    else if (!check[1]) {
        cout << "Why Wrong!!!\n";
    }
    else {
        cout << "Accepted\n";
    }

    return 0;
}
