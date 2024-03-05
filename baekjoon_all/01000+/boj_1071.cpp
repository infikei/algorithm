// Solve 2024-03-04

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int numbers[50];
int answer[50];
bool selected[50];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers, numbers + n);

    answer[0] = numbers[0];
    selected[0] = true;

    for (int i = 1; i < n; i++) {
        int j = 0;

        while (selected[j] || numbers[j] == answer[i - 1] + 1) {
            if (++j == n) {
                break;
            }
        }

        if (j == n) {
            j = 0;

            while (selected[j]) {
                j++;
            }
        }

        answer[i] = numbers[j];
        selected[j] = true;
        j = i;

        while (j >= 1 && answer[j - 1] + 1 == answer[j]) {
            swap(answer[j - 1], answer[j]);
            j--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }

    cout << '\n';

    return 0;
}
