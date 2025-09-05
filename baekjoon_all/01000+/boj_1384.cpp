// Solve 2025-09-02

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

string names[20];

int main() {
    FASTIO;

    int group_num = 0;

    while (true) {
        group_num++;
        int n;
        cin >> n;

        if (n == 0) break;

        vector<pii> negative_messages;

        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;
            names[i] = name;

            for (int j = i + n - 1; j > i; j--) {
                char message;
                cin >> message;

                if (message == 'N') {
                    negative_messages.emplace_back(j % n, i);
                }
            }
        }

        if (group_num >= 2) cout << '\n';

        cout << "Group " << group_num << '\n';

        for (pii& m : negative_messages) {
            cout << names[m.first] << " was nasty about " << names[m.second] << '\n';
        }

        if (negative_messages.empty()) {
            cout << "Nobody was nasty" << '\n';
        }
    }

    return 0;
}
