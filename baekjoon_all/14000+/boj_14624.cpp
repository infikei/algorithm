#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "I LOVE CBNU\n";
    }
    else {
        for (int i = 0; i < n; i++) cout << '*';
        cout << '\n';

        int k = n / 2 + 1;
        for (int ln = 0; ln < k; ln++) {
            int i_end = k - 1 - ln;
            for (int i = 0; i < i_end; i++) cout << ' ';
            cout << '*';

            if (ln > 0) {
                i_end = ln * 2 - 1;
                for (int i = 0; i < i_end; i++) cout << ' ';
                cout << '*';
            }

            cout << '\n';
        }
    }

    return 0;
}