// Solve 2025-11-04

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

string board[200];
set<string> mbti = {
    "ENFP", "ENFJ", "ENTP", "ENTJ",
    "ESFP", "ESFJ", "ESTP", "ESTJ",
    "INFP", "INFJ", "INTP", "INTJ",
    "ISFP", "ISFJ", "ISTP", "ISTJ"
};
int dx[4] = {0, 1, 1, 1};
int dy[4] = {1, -1, 0, 1};

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    int cnt = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int d = 0; d < 4; d++) {
                string cur_word;
                int nx = x;
                int ny = y;

                while (size(cur_word) < 4 && nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    cur_word.push_back(board[nx][ny]);
                    nx += dx[d];
                    ny += dy[d];
                }

                if (size(cur_word) < 4) continue;

                if (mbti.find(cur_word) != mbti.end()) {
                    cnt++;
                }

                reverse(cur_word.begin(), cur_word.end());

                if (mbti.find(cur_word) != mbti.end()) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}
