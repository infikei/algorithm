#include "aplusb.h"
#include <cassert>
#include <cstdio>

int main() {
    int A, B;
    assert(2 == scanf("%d%d", &A, &B));
    fclose(stdin);

    int R = sum(A, B);

    printf("%d\n", R);
    fclose(stdout);

    return 0;
}
