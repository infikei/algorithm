// Solve 2022-06-05
// Update 2023-08-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string line;
    getline(cin, line);

    // 양끝에 공백이 없다고 가정하면, 단어의 개수 = 공백의 개수 + 1이다.
    int ans = 1;
    for (const char &ch : line) {
        if (ch == ' ') {
            ans++;
        }
    }

    // 문장의 시작이 공백인 경우 처리
    if (line[0] == ' ') {
        ans--;
    }

    // 문장의 마지막이 공백인 경우 처리
    if (line[SIZE(line) - 1] == ' ') {
        ans--;
    }

    cout << ans << '\n';

    return 0;
}
