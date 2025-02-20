// Solve 2025-02-19

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

struct Node{
    int prev, next;
};

Node li[500002];
int arr[500001];
int memo_par[500001];
bool lis_included[500001];

void init_li(int n) {
    li[0].next = 1;

    for (int u = 1; u <= n; u++) {
        li[u].prev = u - 1;
        li[u].next = u + 1;
    }
}

void move_node(char cmd, int x, int y) {
    int xp = li[x].prev;
    int xn = li[x].next;
    li[xp].next = xn;
    li[xn].prev = xp;

    if (cmd == 'A') {
        // 노드 x를 노드 y의 앞으로 이동한다.
        int yp = li[y].prev;
        li[yp].next = x;
        li[x].prev = yp;
        li[x].next = y;
        li[y].prev = x;
    }
    else {
        // 노드 x를 노드 y의 뒤로 이동한다.
        int yn = li[y].next;
        li[yn].prev = x;
        li[x].next = yn;
        li[x].prev = y;
        li[y].next = x;
    }
}

void copy_li_to_arr(int n) {
    int li_pos = 0;
    int arr_pos = 0;

    while (li_pos != n + 1) {
        li_pos = li[li_pos].next;
        arr[++arr_pos] = li_pos;
    }
}

int lis(int n) {
    vector<int> memo;
    vector<int> memo_idx;

    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(memo.begin(), memo.end(), arr[i]) - memo.begin();

        if (pos == size(memo)) {
            memo.push_back(arr[i]);
            memo_idx.push_back(i);
        }
        else {
            memo[pos] = arr[i];
            memo_idx[pos] = i;
        }

        if (pos == 0) {
            memo_par[i] = -1;
        }
        else {
            memo_par[i] = memo_idx[pos - 1];
        }
    }

    int pos = memo_idx.back();

    while (pos != -1) {
        lis_included[arr[pos]] = true; // 각 번호마다 LIS에 포함되는지 여부를 lis_included 배열에 기록한다.
        pos = memo_par[pos];
    }

    return size(memo);
}

void create_and_print_cmds(int n) {
    int pos = 1;

    while (!lis_included[pos]) {
        pos++;
    }

    for (int i = 1; i < pos; i++) {
        cout << "A " << i << ' ' << pos << '\n';
    }

    while (pos <= n) {
        if (!lis_included[pos]) {
            cout << "B " << pos << ' ' << pos - 1 << '\n';
        }

        pos++;
    }
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    // 연결 리스트를 처음 상태로 만든다.
    init_li(n);

    for (int i = 0; i < m; i++) {
        char cmd;
        int x, y;
        cin >> cmd >> x >> y;

        move_node(cmd, x, y);
    }

    // 연결 리스트의 현재 상태를 배열에 복사한다.
    copy_li_to_arr(n);

    // LIS를 구한다.
    int lis_size = lis(n);

    cout << n - lis_size << '\n';

    create_and_print_cmds(n);

    return 0;
}
