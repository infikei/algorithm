// Solve 2026-03-22

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

int cnt_class[1001];
int selected_classes;
int mn = INF;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    vector<pii> students;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int d;
            cin >> d;
            students.emplace_back(d, i);
        }
    }

    sort(students.begin(), students.end());

    int i = 0;
    int j = -1;

    while (true) {
        if (selected_classes < n) {
            j++;

            if (j == size(students)) {
                break;
            }

            int j_class = students[j].second;
            cnt_class[j_class]++;

            if (cnt_class[j_class] == 1) {
                selected_classes++;
            }
        }
        else {
            int i_class = students[i].second;
            cnt_class[i_class]--;

            if (cnt_class[i_class] == 0) {
                selected_classes--;
            }

            i++;
        }

        if (selected_classes == n) {
            mn = min(mn, students[j].first - students[i].first);
        }
    }

    cout << mn << '\n';
    return 0;
}
