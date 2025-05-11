// Solve 2025-05-11

// 제출 코드가 아닌 전처리 코드입니다.

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

int main() {
    FASTIO;

    vector<int> a;

    for (int i = 1; i <= 40000; i++) {
        a.push_back(i * (i + 1) / 2 + 1);
    }

    vector<int> b;

    for (int i = 1; i <= 40000; i++) {
        b.push_back(i * i);
    }

    int i = 0;
    int j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            i++;
        }
        else if (a[i] > b[j]) {
            j++;
        }
        else {
            cout << a[i] << '\n';
            i++;
            j++;
        }
    }

    return 0;
}
