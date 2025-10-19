// Solve 2025-10-19

#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int sqrt_n = sqrt(n);
    return (sqrt_n * sqrt_n == n ? 1 : 2);
}
