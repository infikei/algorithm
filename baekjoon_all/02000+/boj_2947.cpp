// Solve 2023-08-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int arr[6];

    for (int i = 1; i <= 5; i++) {
        cin >> arr[i];
    }

    int idx = 1;

    while (true) {
        if (arr[idx] > arr[idx + 1]) {
            swap(arr[idx], arr[idx + 1]);

            bool check = true;

            for (int i = 1; i <= 5; i++) {
                if (arr[i] != i) check = false;

                cout << arr[i] << ' ';
            }
            cout << '\n';

            if (check) break;
        }

        idx++;
        if (idx == 5) idx = 1;
    }

    return 0;
}
