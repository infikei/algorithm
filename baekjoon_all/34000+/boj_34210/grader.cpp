#include "aplusb.h"
#include <cassert>
#include <cstdio>

int main() {
  int N;
  assert(1 == scanf("%d", &N));
  std::vector<int> A(N), B(N);
  for (int k = 0; k < N; k++)
    assert(1 == scanf("%d", &A[k]));
  for (int k = 0; k < N; k++)
    assert(1 == scanf("%d", &B[k]));

  int Q;
  assert(1 == scanf("%d", &Q));
  std::vector<int> i(Q), j(Q);
  for (int k = 0; k < Q; k++)
    assert(2 == scanf("%d %d", &i[k], &j[k]));

  fclose(stdin);

  std::vector<int> S(Q);

  initialize(A, B);

  for (int k = 0; k < Q; k++)
    S[k] = answer_question(i[k], j[k]);

  for (int k = 0; k < Q; k++)
    printf("%d\n", S[k]);

  fclose(stdout);

  return 0;
}
