// Solve 2023-11-26
// Update 2025-03-11

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

int fruits[200000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }

    int left = 0;
    int right = 0;
    int cnt[10] = { 0 };
    int kind_of_fruits = 0;
    int max_len = 0;

    while (right < n) {
        cnt[fruits[right]]++;

        if (cnt[fruits[right]] == 1) {
            kind_of_fruits++;

            while (kind_of_fruits == 3) {
                cnt[fruits[left]]--;

                if (cnt[fruits[left]] == 0) {
                    kind_of_fruits--;
                }

                left++;
            }
        }

        right++;
        int cur_len = right - left;
        max_len = cur_len > max_len ? cur_len : max_len;
    }

    cout << max_len << '\n';

    return 0;
}
