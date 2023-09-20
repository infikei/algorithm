// Solve 2023-09-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Pair{
    int a = 0, b = 0;
    Pair(int a = 0, int b = 0) : a(a), b(b) {}
    bool operator<(const Pair &rhs) const {
        if (a != rhs.a) return a < rhs.a;
        return b < rhs.b;
    }
    bool operator==(const Pair &rhs) const {
        return a == rhs.a && b == rhs.b;
    }
};

int main() {
    FASTIO;

    int s;
    cin >> s;

    if (s % 4763 != 0) {
        cout << 0 << '\n';
    }
    else {
        s /= 4763;

        vector<Pair> ans_vec;

        int a = 0, bb = s;

        while (a <= 200 && bb >= 0) {
            if (bb % 212 == 0) {
                int b = bb / 212;
                if (b >= 0 && b <= 200) {
                    ans_vec.push_back({ a, b });
                }
            }

            if (bb % 305 == 0) {
                int b = bb / 305;
                if (b >= 0 && b <= 200) {
                    ans_vec.push_back({ a, b });
                }
            }

            a++;
            bb -= 508;
        }

        a = 0, bb = s;

        while (a <= 200 && bb >= 0) {
            if (bb % 212 == 0) {
                int b = bb / 212;
                if (b >= 0 && b <= 200) {
                    ans_vec.push_back({ a, b });
                }
            }

            if (bb % 305 == 0) {
                int b = bb / 305;
                if (b >= 0 && b <= 200) {
                    ans_vec.push_back({ a, b });
                }
            }

            a++;
            bb -= 108;
        }

        sort(ans_vec.begin(), ans_vec.end());

        ans_vec.erase(unique(ans_vec.begin(), ans_vec.end()), ans_vec.end());

        cout << SIZE(ans_vec) << '\n';

        for (Pair &ans : ans_vec) {
            cout << ans.a << ' ' << ans.b << '\n';
        }
    }

    return 0;
}
