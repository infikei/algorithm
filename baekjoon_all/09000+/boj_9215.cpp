// Solve 2025-05-11

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

struct Frac{
    int child, parent;

    Frac(int child, int parent) : child(child), parent(parent) {
    }
};

int get_gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

Frac reduce_frac(Frac frac) {
    int gcd = get_gcd(frac.child, frac.parent);
    return { frac.child / gcd, frac.parent / gcd };
}

Frac add_frac(Frac a, Frac b) {
    int child = a.child * b.parent + b.child * a.parent;
    int parent = a.parent * b.parent;
    return reduce_frac({ child, parent });
}

Frac to_frac(string& s) {
    vector<int> nums;
    int num = 0;

    for (char& c : s) {
        if (c == '/' || c == ',') {
            nums.push_back(num);
            num = 0;
        }
        else {
            num = num * 10 + (c - '0');
        }
    }

    nums.push_back(num);

    if (nums.size() == 1) {
        return { nums[0], 1 };
    }

    if (nums.size() == 2) {
        return reduce_frac({ nums[0], nums[1] });
    }

    return reduce_frac({ nums[1] + nums[0] * nums[2], nums[2] });
}

string frac_to_string(Frac& frac) {
    if (frac.parent == 1) {
        return to_string(frac.child);
    }

    if (frac.child < frac.parent) {
        return to_string(frac.child) + "/" + to_string(frac.parent);
    }

    int q = frac.child / frac.parent;
    frac.child %= frac.parent;
    return to_string(q) + "," + to_string(frac.child) + "/" + to_string(frac.parent);
}

int main() {
    FASTIO;

    int ti = 0;

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        Frac frac_sum(0, 1);

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            Frac cur_frac = to_frac(s);
            frac_sum = add_frac(frac_sum, cur_frac);
        }

        cout << "Test " << ++ti << ": " << frac_to_string(frac_sum) << '\n';
    }

    return 0;
}
