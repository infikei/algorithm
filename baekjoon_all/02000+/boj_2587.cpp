// Solve 2022-10-27
// Update 2023-02-26

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int arr[5];
    int avr = 0;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        avr += arr[i];
    }
    avr /= 5;
    sort(arr, arr + 5);

    cout << avr << '\n';
    cout << arr[2] << '\n';

    return 0;
}