// 빠른 선택 (quick select) 알고리즘

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int quick_select(const vector<int> &vt, int k) {
    vector<int> small, same, big;

    int pivot = vt[0];
    int i_end = SIZE(vt);

    for (int i = 0; i < i_end; i++) {
        if (vt[i] < pivot) {
            small.push_back(vt[i]);
        }
        else if (vt[i] > pivot) {
            big.push_back(vt[i]);
        }
        else {
            same.push_back(vt[i]);
        }
    }

    if (SIZE(small) >= k) {
        return quick_select(small, k);
    }
    else if (SIZE(small) + SIZE(same) < k) {
        return quick_select(big, k - SIZE(small) - SIZE(same));
    }
    else {
        return pivot;
    }
}
