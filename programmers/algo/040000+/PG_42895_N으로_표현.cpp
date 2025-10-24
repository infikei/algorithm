// Solve 2025-10-24

#include <bits/stdc++.h>

using namespace std;

int solution(int N, int number) {
    set<int> memo[9];

    int tmp = 0;

    for (int i = 1; i <= 8; i++) {
        tmp = tmp * 10 + N;
        memo[0].insert(tmp);
        memo[i].insert(tmp);
    }

    for (int i = 2; i <= 8; i++) {
        for (int j = i / 2; j >= 1; j--) {
            int jj = i - j;

            for (auto it = memo[j].begin(); it != memo[j].end(); it++) {
                for (auto jt = memo[jj].begin(); jt != memo[jj].end(); jt++) {
                    if (*it == 0 || *jt == 0) continue;

                    tmp = *it + *jt;

                    if (memo[0].find(tmp) == memo[0].end()) {
                        memo[0].insert(tmp);
                        memo[i].insert(tmp);
                    }

                    tmp = (*it > *jt ? *it - *jt : *jt - *it);

                    if (memo[0].find(tmp) == memo[0].end()) {
                        memo[0].insert(tmp);
                        memo[i].insert(tmp);
                    }

                    tmp = *it * *jt;

                    if (memo[0].find(tmp) == memo[0].end()) {
                        memo[0].insert(tmp);
                        memo[i].insert(tmp);
                    }

                    tmp = (*it > *jt ? *it / *jt : *jt / *it);

                    if (memo[0].find(tmp) == memo[0].end()) {
                        memo[0].insert(tmp);
                        memo[i].insert(tmp);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= 8; i++) {
        if (memo[i].find(number) != memo[i].end()) {
            return i;
        }
    }

    return -1;
}
