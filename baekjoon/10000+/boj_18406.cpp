#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    string n;
    cin >> n;
    int n_size = n.length();

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n_size / 2; i++) sum1 += n[i] - '0';
    for (int i = n_size / 2; i < n_size; i++) sum2 += n[i] - '0';

    cout << (sum1 == sum2 ? "LUCKY\n" : "READY\n");

    return 0;
}