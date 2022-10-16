#include <iostream>
using namespace std;
typedef long long ll;

int N;
ll a, b, c;
int ans = 0;
int b_used = 0;
int c_remained = 0;

void dfs(ll res) {
    if (c_remained == 0) {
        if (b_used < N) {
            b_used++;
            c_remained++;
            dfs((res + b) % 100000);
            c_remained--;
            b_used--;
        }
        else {
            ans = max(ans, (int)res);
        }
    }
    else {
        if (b_used < N) {
            b_used++;
            c_remained++;
            dfs((res + b) % 100000);
            c_remained--;
            b_used--;
        }

        c_remained--;
        dfs((res * c) % 100000);
        c_remained++;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> a >> b >> c;

    dfs(a);

    cout << ans << '\n';

    return 0;
}