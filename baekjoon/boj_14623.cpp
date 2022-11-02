#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ull = unsigned long long;

ull binary_to_int(string Nbin) {
    ull N = 0;

    for (int i = 0; i < Nbin.length(); i++) {
        N *= 2;
        N += (Nbin[i] - '0');
    }

    return N;
}

string int_to_binary(ull N) {
    string Nbin;

    while (N > 0) {
        Nbin = to_string(N % 2) + Nbin;
        N /= 2;
    }

    return Nbin;
}

int main() {
    fastio;

    string Abin, Bbin;
    cin >> Abin >> Bbin;

    ull A = binary_to_int(Abin);
    ull B = binary_to_int(Bbin);

    string ans = int_to_binary(A * B);
    cout << ans << '\n';

    return 0;
}