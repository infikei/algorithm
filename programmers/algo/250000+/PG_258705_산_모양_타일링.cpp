// Solve 2025-10-09

#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> tops) {
    const int MOD = 10007;

    int prv2 = 1;
    int prv = 1;

    for (int i = 2; i <= 2 * n + 1; i++) {
        int cur;

        if (i % 2 == 0 && tops[i / 2 - 1] == 1) {
            cur = (prv2 + 2 * prv) % MOD;
        }
        else {
            cur = (prv2 + prv) % MOD;
        }

        prv2 = prv;
        prv = cur;
    }

    return prv;
}
