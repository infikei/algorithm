// Solve 2025-10-19

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solution(vector<int> num_list) {
    ll prod = 1;
    ll sum = 0;

    for (int& num : num_list) {
        prod *= num;
        sum += num;
    }

    return (prod < sum * sum ? 1 : 0);
}
