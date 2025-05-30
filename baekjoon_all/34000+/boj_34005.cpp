// Solve 2025-05-29

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int memo[601][101][3][8];

int solution(int a, int b, int c, int p) {
    for (int t = 0; t <= 600; t++) {
        for (int sp = 0; sp <= 100; sp++) {
            for (int cool_b = 0; cool_b < 3; cool_b++) {
                for (int cool_c = 0; cool_c < 8; cool_c++) {
                    memo[t][sp][cool_b][cool_c] = -100000000;
                }
            }
        }
    }

    memo[0][100][0][0] = 0;

    for (int t = 0; t <= 600; t++) {
        for (int sp = 0; sp <= 100; sp++) {
            for (int cool_b = 0; cool_b < 3; cool_b++) {
                for (int cool_c = 0; cool_c < 8; cool_c++) {
                    int cur_damage = memo[t][sp][cool_b][cool_c];
                    int nt = t + 1;

                    if (cur_damage >= p) return t;
                    if (nt > 600) continue;

                    int nsp, ncool_b, ncool_c;

                    // 직전 시각에 스트라이크 또는 박치기 사용한 경우
                    if (cool_b == 2 || cool_c == 7) {
                        nsp = min(sp + 1, 100);
                        ncool_b = max(cool_b - 1, 0);
                        ncool_c = max(cool_c - 1, 0);
                        memo[nt][nsp][ncool_b][ncool_c] = max(memo[nt][nsp][ncool_b][ncool_c], cur_damage);
                        continue;
                    }

                    // 기본 공격
                    nsp = min(sp + 1, 100);
                    ncool_b = max(cool_b - 1, 0);
                    ncool_c = max(cool_c - 1, 0);
                    memo[nt][nsp][ncool_b][ncool_c] = max(memo[nt][nsp][ncool_b][ncool_c], cur_damage + 100);

                    // 해머링
                    nsp = min(sp + 8, 100);
                    memo[nt][nsp][ncool_b][ncool_c] = max(memo[nt][nsp][ncool_b][ncool_c], cur_damage + a);

                    // 스트라이크
                    if (cool_b == 0 && sp >= 10) {
                        nsp = max(sp - 9, 0);
                        ncool_b = 2;
                        ncool_c = max(cool_c - 1, 0);
                        memo[nt][nsp][ncool_b][ncool_c] = max(memo[nt][nsp][ncool_b][ncool_c], cur_damage + b);
                    }

                    // 박치기
                    if (cool_c == 0 && sp >= 10) {
                        nsp = max(sp - 9, 0);
                        ncool_b = max(cool_b - 1, 0);
                        ncool_c = 7;
                        memo[nt][nsp][ncool_b][ncool_c] = max(memo[nt][nsp][ncool_b][ncool_c], cur_damage + c);
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int a, b, c, p;
        cin >> a >> b >> c >> p;

        cout << solution(a, b, c, p) << '\n';
    }

    return 0;
}
