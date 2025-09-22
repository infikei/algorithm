// Solve 2025-09-22

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

struct Point{
    int x, y;

    Point(int x, int y) : x(x), y(y) {
    }
};

int h, w;
string board[100];
bool visited[100][100];
bool keys[26];
string first_keys;
queue<Point> main_que;
queue<Point> door_que[26];
int doc_cnt = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void visit(int x, int y) {
    if (x < 0 || x >= h || y < 0 || y >= w || visited[x][y]) return;

    visited[x][y] = true;
    char c = board[x][y];

    if (c == '*') {
        return;
    }
    else if (c == '.') {
        main_que.emplace(x, y);
    }
    else if (c == '$') {
        doc_cnt++;
        main_que.emplace(x, y);
    }
    else if (isupper(c)) {
        if (keys[c - 'A']) {
            main_que.emplace(x, y);
        }
        else {
            door_que[c - 'A'].emplace(x, y);
        }
    }
    else if (islower(c)) {
        keys[c - 'a'] = true;
        queue<Point>& cur_door_que = door_que[c - 'a'];
        main_que.emplace(x, y);

        while (!cur_door_que.empty()) {
            main_que.push(cur_door_que.front());
            cur_door_que.pop();
        }
    }
}

void init() {
    memset(visited, false, sizeof visited);
    memset(keys, false, sizeof keys);
    doc_cnt = 0;

    while (!main_que.empty()) {
        main_que.pop();
    }

    for (int i = 0; i < 26; i++) {
        while (!door_que[i].empty()) {
            door_que[i].pop();
        }
    }
}

void input() {
    cin >> h >> w;

    for (int x = 0; x < h; x++) {
        cin >> board[x];
    }

    cin >> first_keys;

    if (first_keys == "0") {
        first_keys = "";
    }
}

void pro() {
    for (char c : first_keys) {
        keys[c - 'a'] = true;
    }

    for (int x = 0; x < h; x++) {
        visit(x, 0);
        visit(x, w - 1);
    }

    for (int y = 0; y < w; y++) {
        visit(0, y);
        visit(h - 1, y);
    }

    while (!main_que.empty()) {
        Point cur = main_que.front();
        main_que.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            visit(nx, ny);
        }
    }
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        init(); // 변수 초기화
        input(); // 데이터 입력
        pro(); // 데이터 처리
        cout << doc_cnt << '\n';
    }

    return 0;
}
