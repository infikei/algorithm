// Solve 2023-03-30
// Update 2023-11-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int s[2];
    cin >> s[0] >> s[1];

    bool check[2];

    for (int si = 0; si < 2; si++) {
        check[si] = true;

        for (int i = 0; i < s[si]; i++) {
            int test_case_ans, submitted_ans;
            cin >> test_case_ans >> submitted_ans;

            if (test_case_ans != submitted_ans) {
                check[si] = false;

                // 이후 입력들을 모두 받아주고 break
                for (; i < s[si]; i++) {
                    cin >> test_case_ans >> submitted_ans;
                }
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
