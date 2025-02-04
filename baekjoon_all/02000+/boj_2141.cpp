// Solve 2025-02-01

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

struct Village{
    int pos;
    ll people;

    Village() {
    }

    Village(int pos, ll people) : pos(pos), people(people) {
    }

    bool operator<(const Village &rhs) const {
        return pos < rhs.pos;
    }

    void add(ll people_add) {
        people += people_add;
    }
};

Village villages[100000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int xi, ai;
        cin >> xi >> ai;

        villages[i] = { xi, ai };
    }

    // 마을을 위치에 따라 오름차순 정렬한다.
    sort(villages, villages + n);

    // 인구 수를 누적합으로 변환
    for (int i = 1; i < n; i++) {
        villages[i].add(villages[i - 1].people);
    }

    ll people_sum = villages[n - 1].people;

    // 모든 사람들 중에서 가장 중앙에 위치한 사람이 어느 마을에 속해있는지 찾는다.
    ll middle_of_people = (people_sum + 1) / 2;
    int low = -1;
    int high = n;

    while (low + 1 < high) {
        int mid = (low + high) / 2;

        if (villages[mid].people >= middle_of_people) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    println(villages[high].pos);

    return 0;
}
