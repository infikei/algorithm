#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

void solve(ll n) {
    string s = to_string(n);
    bool check = true;
    for (auto a : s) {
        if (a != '0' && a != '1') {
            check = false;
            break;
        }
    }
    if (check) {
        cout << "Hello, BOJ 2023!\n";
        return;
    }

    vector<ll> vec[10];
    for (int i = 0; i < s.length(); i++) {
        vec[i].push_back(stoll(s.substr(0, i + 1)));
        for (int j = 0; j < i; j++) {
            ll tmp = stoll(s.substr(j + 1, i - j));
            for (auto a : vec[j]) {
                vec[i].push_back(a + tmp);
            }
        }

        // 정렬 후 중복 제거
        sort(vec[i].begin(), vec[i].end());
        vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
    }

    ll vec_max = vec[s.length() - 1].back();
    int res = 0, iter = 1;
    while (true) {
        ll n_sum = 0, n_tmp = n;
        while (n_tmp > 0) {
            n_sum += pow(n_tmp % 10, iter);
            n_tmp /= 10;
        }
        if (n_sum > vec_max) break;

        for (auto a : vec[s.length() - 1]) {
            if (a == n_sum) {
                res++;
                break;
            }
        }
        iter++;
    }
    cout << res << '\n';
}

int main() {
    fastio;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        ll n;
        cin >> n;

        solve(n);
    }

    return 0;
}