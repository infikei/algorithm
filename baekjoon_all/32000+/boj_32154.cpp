// Solve 2024-09-08

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string ans[11] = {
        "",
        "11\nA B C D E F G H J L M\n",
        "9\nA C E F G H I L M\n",
        "9\nA C E F G H I L M\n",
        "9\nA B C E F G H L M\n",
        "8\nA C E F G H L M\n",
        "8\nA C E F G H L M\n",
        "8\nA C E F G H L M\n",
        "8\nA C E F G H L M\n",
        "8\nA C E F G H L M\n",
        "8\nA B C F G H L M\n"
    };

    int n;
    cin >> n;

    cout << ans[n] << '\n';

    return 0;
}
