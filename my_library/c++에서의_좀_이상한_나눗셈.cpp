#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    FASTIO;

    // 직접 실행하여 결과를 확인할 것

    for (int i = -5; i <= 5; i++) {
        cout << i << " / 3 = " << i / 3 << " ... " << i % 3 << '\n';
    }

    for (int i = -5; i <= 5; i++) {
        cout << i << " / (-3) = " << i / (-3) << " ... " << i % (-3) << '\n';
    }

    return 0;
}