// Solve 2026-03-01

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

int get_gcd(int a, int b) {
    if (a < 0) a = -a;

    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

vector<int> parse_term(string& term) {
    int idx = 0;

    // 부호 처리
    int sign = 1; // 부호

    if (term[idx] == '-') {
        sign = -1;
        idx++;
    }

    // 계수 처리
    int child = 0; // 분자
    int par = 1; // 분모

    if (term[idx] == 'x') {
        child = 1;
    }
    else {
        bool par_flag = false;

        while (idx < size(term) && term[idx] != 'x') {
            if (term[idx] == '/') {
                par_flag = true;
                par = 0;
            }
            else if (par_flag) {
                par = par * 10 + (term[idx] - '0');
            }
            else {
                child = child * 10 + (term[idx] - '0');
            }

            idx++;
        }
    }

    if (sign == -1) {
        child *= sign;
    }

    // 'x' 확인
    if (idx == size(term)) {
        return {child, par, 0};
    }

    idx++;

    // '^' 확인
    if (idx == size(term)) {
        return {child, par, 1};
    }

    idx++;

    // 차수 처리
    int exp = 0; // 차수

    while (idx < size(term)) {
        exp = exp * 10 + (term[idx] - '0');
        idx++;
    }

    return {child, par, exp};
}

vector<string> split_polynomial(string& polynomial) {
    vector<string> terms;
    terms.push_back("");
    terms[0].push_back(polynomial[0]);

    for (int i = 1; i < size(polynomial); i++) {
        if (polynomial[i] == '+') {
            terms.push_back("");
        }
        else if (polynomial[i] == '-') {
            terms.push_back("");
            terms.back().push_back('-');
        }
        else {
            terms.back().push_back(polynomial[i]);
        }
    }

    return terms;
}

void pro() {
    string p0, p2;
    cin >> p0 >> p2;

    vector<string> p0_terms = split_polynomial(p0);
    vector<string> p2_terms = split_polynomial(p2);

    // 다항식 p2가 "0"일 경우 항 제거
    if (p2_terms.back() == "0") {
        p2_terms.pop_back();
    }

    if (size(p0_terms) != size(p2_terms) + 2) {
        cout << "No" << '\n';
        return;
    }

    // 다항식 p0에서 "Cx", "D" 항 제거
    p0_terms.pop_back();
    p0_terms.pop_back();

    for (int i = 0; i < size(p0_terms); i++) {
        vector<int> p0_term = parse_term(p0_terms[i]);
        vector<int> p2_term = parse_term(p2_terms[i]);

        p0_term[0] *= p0_term[2] * (p0_term[2] - 1);
        p0_term[2] = p0_term[2] - 2;

        int gcd = get_gcd(p0_term[0], p0_term[1]);
        p0_term[0] /= gcd;
        p0_term[1] /= gcd;

        if (p0_term != p2_term) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        pro();
    }

    return 0;
}
