// Solve 2024-09-26

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    cin >> n >> s;

    for (int i = 3; i < n; i++) {
        if (s.substr(i - 3, 4) == "gori") {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
