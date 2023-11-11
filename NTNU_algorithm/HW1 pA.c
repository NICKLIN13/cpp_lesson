#include <stdio.h>
#define MAXN 10000
int insertsort(int[], int, int);
int find(int[], int, int);
int main() {
  int scores[MAXN] = {0};
  int n, q, op, x, v;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &scores[i]);
  }

  for (int i = 0; i < q; i++) {
    scanf("%d", &op);
    //	printf("op: %d", op);
    if (op == 1) {
      scanf("%d%d", &x, &v);
      // Do somthing else
      scores[x] = v;
    }
    if (op == 2) {
      scanf("%d", &x);
      printf("%d\n", find(scores, x, n) + 1);
      // printf("%d\n", insertsort(scores, x, n));
    }
  }
  return 0;
}

int find(int scores[], int x, int n) {
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (scores[i] < scores[x])
      count++;
    else if (scores[i] == scores[x] && i < x)
      count++;
  }
  return count;
}