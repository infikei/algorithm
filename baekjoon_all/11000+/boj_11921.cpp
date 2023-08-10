// Solve 2023-08-10

#include <stdio.h>

const int MAX = 1 << 20;

char buf[MAX];
int pos = MAX;

inline char read_buf() {
    if (pos == MAX) {
        fread(buf, 1, MAX, stdin);
        pos = 0;
    }

    return buf[pos++];
}

inline void read_int(int &x) {
    x = read_buf() & 15;
    int tmp = read_buf();

    while (tmp != '\n') {
        x = x * 10 + (tmp & 15);
        tmp = read_buf();
    }
}

int main() {
    int n, a, i;
    long long s = 0;

    read_int(n);

    for (i = 0; i < n; i++) {
        read_int(a);
        s += a;
    }

    printf("%d\n%lld", n, s);

    return 0;
}
