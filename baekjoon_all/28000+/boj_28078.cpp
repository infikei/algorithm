// Solve 2025-07-09

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

deque<char> dque;
int direction = 0;
int b_cnt = 0;
int w_cnt = 0;

void push(char b_or_w) {
    dque.push_back(b_or_w);

    if (b_or_w == 'b') b_cnt++;
    else w_cnt++;
}

void pop() {
    if (dque.empty()) return;

    if (dque.front() == 'b') b_cnt--;
    else w_cnt--;

    dque.pop_front();
}

void rotate(char l_or_r) {
    if (l_or_r == 'l') {
        direction = (direction + 3) % 4;
    }
    else {
        direction = (direction + 1) % 4;
    }
}

int count(char b_or_w) {
    return b_or_w == 'b' ? b_cnt : w_cnt;
}

void gravity() {
    if (direction == 1) {
        while (!dque.empty() && dque.front() == 'b') {
            dque.pop_front();
            b_cnt--;
        }
    }
    else if (direction == 3) {
        while (!dque.empty() && dque.back() == 'b') {
            dque.pop_back();
            b_cnt--;
        }
    }
}

int main() {
    FASTIO;

    int q;
    cin >> q;

    while (q-- > 0) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            char b_or_w;
            cin >> b_or_w;
            push(b_or_w);
        }
        else if (cmd == "pop") {
            pop();
        }
        else if (cmd == "rotate") {
            char l_or_r;
            cin >> l_or_r;
            rotate(l_or_r);
        }
        else if (cmd == "count") {
            char b_or_w;
            cin >> b_or_w;
            cout << count(b_or_w) << '\n';
        }

        gravity();
    }

    return 0;
}
