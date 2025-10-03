// Solve 2025-10-03

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

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int k;
        cin >> k;
        set<int> student_id;

        for (int i = 0; i < k; i++) {
            int id;
            cin >> id;
            student_id.insert(id);
        }

        int n;
        cin >> n;
        int n_certified_student = 0;
        int min_t = INF;
        int id_of_min_t = -1;

        for (int i = 0; i < n; i++) {
            int id, hh, mm;
            cin >> id >> hh >> mm;

            if (hh == -1 || student_id.find(id) == student_id.end()) {
                continue;
            }

            int t = hh * 60 + mm;

            if (t > 360) continue;

            n_certified_student++;

            if (t < min_t) {
                min_t = t;
                id_of_min_t = id;
            }
        }

        cout << id_of_min_t << ' ' << n_certified_student << '\n';
    }

    return 0;
}
