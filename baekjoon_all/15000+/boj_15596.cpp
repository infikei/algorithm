// Solve 2022-06-03
// Update 2025-10-10

#include <bits/stdc++.h>

using namespace std;

long long sum(vector<int>& a) {
    long long ans = 0;

    for (int i = 0; i < a.size(); i++) {
        ans += a[i];
    }

    return ans;
}
