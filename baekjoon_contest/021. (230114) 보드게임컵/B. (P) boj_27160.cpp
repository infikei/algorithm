#include <iostream>
#include <string>
#include <unordered_map>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int n, cnt[4];
bool check;
unordered_map<string, int> hs;

int main() {
    fastio;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string fruit;
        int x;
        cin >> fruit >> x;
        if (hs.find(fruit) == hs.end()) hs[fruit] = hs.size();
        cnt[hs[fruit]] += x;
    }

    for (int i = 0; i < 4; i++) {
        if (cnt[i] == 5) {
            check = true;
            break;
        }
    }

    if (check) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}