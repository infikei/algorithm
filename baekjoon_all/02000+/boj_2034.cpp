// Solve 2025-11-11

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

int pitch_value[128];
char pitch_name[12] = {'A', '.', 'B', 'C', '.', 'D', '.', 'E', 'F', '.', 'G', '.'};

int main() {
    FASTIO;

    pitch_value['A'] = 0;
    pitch_value['B'] = 2;
    pitch_value['C'] = 3;
    pitch_value['D'] = 5;
    pitch_value['E'] = 7;
    pitch_value['F'] = 8;
    pitch_value['G'] = 10;

    int n;
    cin >> n;

    set<int> st;
    int cur = 0;
    st.insert(0);

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        cur = (cur + v + 24) % 12;
        st.insert(cur);
    }

    int last = cur;

    for (char c = 'A'; c <= 'G'; c++) {
        int x0 = pitch_value[c];
        bool valid = true;

        for (int dx : st) {
            int x = (x0 + dx) % 12;

            if (pitch_name[x] == '.') {
                valid = false;
                break;
            }
        }

        if (valid) {
            int x_last = (pitch_value[c] + last) % 12;
            cout << c << ' ' << pitch_name[x_last] << '\n';
        }
    }

    return 0;
}
