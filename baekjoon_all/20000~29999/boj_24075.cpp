#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int A, B;
    cin >> A >> B;

    cout << max(A + B, A - B) << '\n';
    cout << min(A + B, A - B) << '\n';

    return 0;
}