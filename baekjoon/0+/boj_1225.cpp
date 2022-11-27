#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ll = long long;

int main() {
    fastio;

    string A, B;
    cin >> A >> B;

    int A_sum_of_each_digit = 0;
    for (auto a : A) {
        A_sum_of_each_digit += (a - '0');
    }
    int B_sum_of_each_digit = 0;
    for (auto b : B) {
        B_sum_of_each_digit += (b - '0');
    }

    ll ans = (ll)A_sum_of_each_digit * (ll)B_sum_of_each_digit;
    cout << ans << '\n';

    return 0;
}