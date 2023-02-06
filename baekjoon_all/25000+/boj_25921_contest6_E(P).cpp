#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ll = long long;

int N;
ll cnt;
bool check[1000001];

int main() {
    fastio;

    cin >> N;

    check[1] = true;

    for (int i = 2; i <= N; i++) {
        if (check[i]) {
            continue;
        }

        for (int j = i; j <= N; j += i) {
            if (check[j]) {
                continue;
            }
            cnt += (ll)i;
            check[j] = true;
        }
    }

    cout << cnt << '\n';

    return 0;
}