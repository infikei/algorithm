// Solve 2025-04-03

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

struct Stage{
    double mi, ti, fi;
};

int main() {
    FASTIO;

    SETP(2);

    int k;
    cin >> k;

    for (int ki = 1; ki <= k; ki++) {
        int n;
        double m;
        cin >> n >> m;

        vector<Stage> stages(n);

        for (Stage &stage : stages) {
            cin >> stage.mi >> stage.ti >> stage.fi;
            m += stage.mi;
        }

        double v = 0;
        double h = 0;

        for (Stage &stage : stages) {
            double ai = stage.fi / m - 9.81;
            h += v * stage.ti + 0.5 * ai * stage.ti * stage.ti;
            v += ai * stage.ti;
            m -= stage.mi;
        }

        if (ki >= 2) cout << '\n';

        cout << "Data Set " << ki << ":" << '\n';
        cout << h << '\n';
    }

    return 0;
}
