// Solve 2023-04-30

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int n;
    cin >> n;
    cin.ignore();

    regex re("<HTML><BODY>[^<>]*</BODY></HTML>");
    regex re_text("<B>[^<>]*</B>|<I>[^<>]*</I>|<A HREF=http://[^<>]*\\.com>[^<>]*</A>");
    smatch match;

    for (int ni = 0; ni < n; ni++) {
        string html;
        getline(cin, html);

        while (regex_search(html, match, re_text)) {
            html = regex_replace(html, re_text, "");
        }

        if (regex_match(html, match, re)) {
            cout << "Syntax Included\n";
        }
        else {
            cout << "No Syntax Included\n";
        }
    }


    return 0;
}
