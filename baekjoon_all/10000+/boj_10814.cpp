// Solve 2023-10-10
// Update 2023-12-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Member{
    int age;
    string name;

    Member(int age, string name) : age(age), name(name) {}
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Member> members[201];

    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;

        members[age].emplace_back(age, name);
    }

    for (int age = 0; age <= 200; age++) {
        for (Member &member : members[age]) {
            cout << member.age << ' ' << member.name << '\n';
        }
    }

    return 0;
}
