// Solve 2022-06-05
// Update 2023-10-10

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

    // 문장의 시작과 마지막에 공백이 없다고 가정하면, 단어의 개수 = 공백의 개수 + 1이다.

    int ans = 1;

    for (char &ch : line) {
        if (ch == ' ') ans++;
    }

    // 문장의 시작 또는 마지막이 공백인 경우를 처리한다.

    if (line[0] == ' ') ans--;

    if (line.back() == ' ') ans--;

    cout << ans << '\n';

    return 0;
}
