// Solve 2022-06-03
// Update 2023-03-13

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

    while (true) {
        int arr[3];
        for (int i = 0; i < 3; i++) {
            cin >> arr[i];
            arr[i] *= arr[i];
        }
        if (arr[0] == 0) {
            break;
        }
        sort(arr, arr + 3);

        if (arr[0] + arr[1] == arr[2]) {
            cout << "right\n";
        }
        else {
            cout << "wrong\n";
        }
    }

    return 0;
}
