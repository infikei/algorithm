// Solve 2025-02-10
// Update 2025-10-15

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

    Point() {
    }

    Point(int x, int y) : x(x), y(y) {
    }
};

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool is_same_line(Point& p1, Point& p2) {
    return p1.x == p2.x || p1.y == p2.y || (p1.x + p1.y == p2.x + p2.y) || (p1.x - p1.y == p2.x - p2.y);
}

bool is_checked(Point king, vector<Point>& queens) {
    for (Point& queen : queens) {
        if (is_same_line(king, queen)) {
            return true;
        }
    }

    return false;
}

bool is_mate(Point king, vector<Point>& queens, int n) {
    for (int d = 0; d < 8; d++) {
        int nx = king.x + dx[d];
        int ny = king.y + dy[d];

        if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;

        if (!is_checked({nx, ny}, queens)) {
            return false;
        }
    }

    return true;
}

string solution(Point king, vector<Point>& queens, int n) {
    bool checked = is_checked(king, queens);
    bool mate = is_mate(king, queens, n);

    if (checked) return (mate ? "CHECKMATE" : "CHECK");
    else return (mate ? "STALEMATE" : "NONE");
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;
    Point king;
    cin >> king.x >> king.y;
    vector<Point> queens(k);

    for (int i = 0; i < k; i++) {
        cin >> queens[i].x >> queens[i].y;
    }

    cout << solution(king, queens, n) << '\n';
    return 0;
}
