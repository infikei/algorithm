// Solve 2024-09-15

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string d[7] = {
        "",
        "Yakk",
        "Doh",
        "Seh",
        "Ghar",
        "Bang",
        "Sheesh"
    };

    string s[7] = {
        "",
        "Habb Yakk",
        "Dobara",
        "Dousa",
        "Dorgy",
        "Dabash",
        "Dosh"
    };

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int a, b;
        cin >> a >> b;

        if (a < b) swap(a, b);

        cout << "Case " << ti << ": ";

        if (a == b) {
            cout << s[a] << '\n';
        }
        else if (a == 6 && b == 5) {
            cout << "Sheesh Beesh\n";
        }
        else {
            cout << d[a] << ' ' << d[b] << '\n';
        }
    }

    return 0;
}
