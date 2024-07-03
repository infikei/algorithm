// Solve 2023-08-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Person{
    int x, s1, s2;
    Person(int x, string s) : x(x) {
        s1 = s[0] - '0';
        s2 = s[1] - 'A';
    }
    bool operator<(const Person &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        if (s1 != rhs.s1) return s1 < rhs.s1;
        return s2 < rhs.s2;
    }
    bool operator==(const Person &rhs) const {
        return x == rhs.x && s1 == rhs.s1 && s2 == rhs.s2;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    int a[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> a[i][j];
        }
    }

    int b[12][12];

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> b[i][j];
        }
    }

    map<Person, int> mp;

    for (int i = 0; i < n; i++) {
        int x;
        string s;
        cin >> x >> s;

        Person p(x, s);
        auto it = mp.find(p);

        if (it == mp.end()) {
            mp.insert({ p, 1 });
        }
        else {
            it->second++;
        }
    }

    int ans = 0;

    for (auto it = mp.begin(); it != mp.end(); it++) {
        it->second--;

        for (auto it2 = it; it2 != mp.end(); it2++) {
            if (it2->second <= 0) continue;
            it2->second--;

            int val = it->first.x + it2->first.x;
            val += a[it->first.s1][it2->first.s1] + b[it->first.s2][it2->first.s2];

            for (auto it3 = it2; it3 != mp.end(); it3++) {
                if (it3->second <= 0) continue;

                int val2 = val + it3->first.x;
                val2 += a[it3->first.s1][it->first.s1] + a[it3->first.s1][it2->first.s1];
                val2 += b[it3->first.s2][it->first.s2] + b[it3->first.s2][it2->first.s2];

                ans = max(ans, val2);
            }

            it2->second++;
        }

        it->second++;
    }

    cout << ans << '\n';

    return 0;
}
