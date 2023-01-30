#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

string ans_str[2] = {"BOJ 2022", "Good Bye"};

int number_type(int k) {
    int sum1 = 0;
    for (int i = 1; i < k; i++) {
        int ii = k / i;
        if (i > ii) break;
        if (k % i != 0) continue;
        if (i == ii) {
            sum1 += i;
            break;
        }
        if (ii == k) {
            sum1 += i;
            continue;
        }
        sum1 += i + ii;
    }

    if (sum1 < k) return -1; // 부족수
    else if (sum1 > k) return 1; // 과잉수
    else return 0; // 완전수
}

int check(int k) {
    for (int i = 1; i < k; i++) {
        int ii = k / i;
        if (i > ii) break;
        if (k % i != 0) continue;
        if (number_type(i) > 0) return 0;
        if (ii != k && number_type(ii) > 0) return 0;
    }
    if (number_type(k) < 1) return 0;
    return 1;
}

int main() {
    fastio;

    int testcase;
    cin >> testcase;

    for (int t = 0; t < testcase; t++) {
        int n;
        cin >> n;

        int ans = check(n);
        cout << ans_str[ans] << '\n';
    }

    return 0;
}