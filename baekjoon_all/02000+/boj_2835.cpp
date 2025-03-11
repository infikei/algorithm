// Solve 2025-03-11

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

ll arr[86401]; // 24h = (24 * 3600)s = 86400s

int time_str_to_int(string &s) {
    int hh = (s[0] - '0') * 10 + (s[1] - '0');
    int mm = (s[3] - '0') * 10 + (s[4] - '0');
    int ss = (s[6] - '0') * 10 + (s[7] - '0');

    return hh * 3600 + mm * 60 + ss;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s1;
        string s2;
        char ch;
        cin >> s1 >> ch >> s2;

        int t1 = time_str_to_int(s1);
        int t2 = time_str_to_int(s2);

        if (t1 <= t2) {
            arr[t1]++;
            arr[t2 + 1]--;
        }
        else {
            arr[t1]++;
            arr[86400]--;
            arr[0]++;
            arr[t2 + 1]--;
        }
    }

    // imos algorithm
    for (int i = 1; i <= 86400; i++) {
        arr[i] += arr[i - 1];
    }

    // prefix sum
    for (int i = 1; i <= 86400; i++) {
        arr[i] += arr[i - 1];
    }

    int q;
    cin >> q;

    SETP(10);

    while (q-- > 0) {
        string s1;
        string s2;
        char ch;
        cin >> s1 >> ch >> s2;

        int t1 = time_str_to_int(s1);
        int t2 = time_str_to_int(s2);

        ll sum = 0;
        int len = 0;

        if (t1 <= t2) {
            sum = arr[t2] - (t1 >= 1 ? arr[t1 - 1] : 0);
            len = t2 - t1 + 1;
        }
        else {
            sum = arr[86399] - arr[t1 - 1] + arr[t2] - 0;
            len = 86400 - t1 + t2 + 1;
        }

        double avg = (double) sum / len;
        cout << avg << '\n';
    }

    return 0;
}
