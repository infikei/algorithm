// Solve 2025-10-19

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll get_gcd(ll a, ll b) {
    while (b > 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}

ll get_lcm(ll a, ll b) {
    return a / get_gcd(a, b) * b;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(get_gcd(n, m));
    answer.push_back(get_lcm(n, m));
    return answer;
}
