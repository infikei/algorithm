// Solve 2024-04-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

bool prime_check[4000];
vector<int> primes;
string num;
int digit_cnt[10];
unordered_set<int> primes_set;

bool is_prime(int k) {
    if (k <= 1) return false;

    for (int prime : primes) {
        if (k == prime) {
            return true;
        }

        if (k % prime == 0) {
            return false;
        }
    }

    return true;
}

void recur(int depth = 0, int cur_num = 0) {
    if (is_prime(cur_num)) {
        primes_set.insert(cur_num);
    }

    if (depth == SIZE(num)) {
        return;
    }

    for (int d = 0; d < 10; d++) {
        if (digit_cnt[d] > 0) {
            digit_cnt[d]--;
            recur(depth + 1, cur_num * 10 + d);
            digit_cnt[d]++;
        }
    }
}

int main() {
    FASTIO;

    for (int i = 2; i < 4000; i++) {
        prime_check[i] = true;
    }

    for (int i = 2; i < 4000; i++) {
        if (prime_check[i]) {
            primes.push_back(i);

            for (int j = i + i; j < 4000; j += i) {
                prime_check[j] = false;
            }
        }
    }

    int t;
    cin >> t;

    while (t-- > 0) {
        cin >> num;

        for (int d = 0; d < 10; d++) {
            digit_cnt[d] = 0;
        }

        for (char digit : num) {
            digit_cnt[digit - '0']++;
        }

        primes_set.clear();
        recur();
        cout << SIZE(primes_set) << '\n';
    }

    return 0;
}
