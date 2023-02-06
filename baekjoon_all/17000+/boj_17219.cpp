#include <iostream>
#include <string>
#include <unordered_map>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int n, m;
unordered_map<string, string> hs;

int main() {
    fastio;

    cin >> n >> m;

    string site, password;
    for (int i = 0; i < n; i++) {
        cin >> site >> password;
        hs[site] = password;
    }

    for (int i = 0; i < m; i++) {
        cin >> site;
        cout << hs[site] << '\n';
    }

    return 0;
}