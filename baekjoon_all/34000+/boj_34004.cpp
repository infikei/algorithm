// Solve 2025-05-27

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

void init_mid_points(vector<pii>& mid_points) {
    int a = 1;
    int b = 1;
    int c = 1;

    for (int i = 1; i <= 100; i++) {
        mid_points.emplace_back(a * b * c, ((a + b) * c + a * b) * 2);
        c++;
        mid_points.emplace_back(a * b * c, ((a + b) * c + a * b) * 2);
        b++;
        mid_points.emplace_back(a * b * c, ((a + b) * c + a * b) * 2);
        a++;
    }
}

int volume_to_n(int v, int a, int n) {
    if (v == n) return a;
    a += 4;
    v++;
    if (v == n) return a;
    a += 2;
    v++;
    if (v == n) return a;

    int i = 2;

    while (true) {
        a += 2;
        v += i;
        if (n <= v) return a;

        a += 2;
        v += i;
        if (n <= v) return a;

        i++;
    }
}

int main() {
    FASTIO;

    vector<pii> mid_points;
    init_mid_points(mid_points);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        int low = -1;
        int high = mid_points.size();

        while (low + 1 < high) {
            int mid = (low + high) / 2;

            if (mid_points[mid].first <= n) {
                low = mid;
            }
            else {
                high = mid;
            }
        }

        int volume = mid_points[low].first;
        int area = mid_points[low].second;
        cout << volume_to_n(volume, area, n) << '\n';
    }

    return 0;
}
