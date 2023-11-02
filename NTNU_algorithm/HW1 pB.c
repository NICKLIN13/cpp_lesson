#include <stdio.h>
#define MAXN 500001
int main() {
  int T[MAXN] = {0};
  int totalk[500001] = {0};
  int n, m, u, v, k;
  int ifprint = 0;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; i++) { // 輸入自己期望的探索度
    scanf("%d", &T[i]);
  }

  for (int i = 0; i < m; i++) { // 總共會做m次（天）
    scanf("%d%d%d", &u, &v, &k);
    for (int q = u; q <= v; q++) { // 把k加進u位置，重複做
      totalk[q] = totalk[q] + k;
    }
    int ifcomplete = 1;
    for (int j = 0; j < n; j++) { // 檢查每個區域是否都有達到探索度
      if (T[j] > totalk[j]) {
        ifcomplete =
            0; // 如果沒達成，把ifcomplete設成0，繼續下一天計劃。達成了，就會進下一個if述句
        break;
      }
    }
    if (ifcomplete == 1 &&
        ifprint ==
            0) { //如果達成了才會做。用ifprint來控制讓程式只印出達成目標的那天
      printf("%d\n", i + 1);
      ifprint = 1;
    }
  }

  // 如果沒辦法完成，印出-1
  int ifcomplete = 1;
  for (int j = 0; j < n; j++) {
    if (T[j] > totalk[j]) { // 檢查是否有達成目標探索度
      ifcomplete = 0;
      break;
    }
  }
  if (ifcomplete == 0) {
    printf("-1\n");
  }
  return 0;
}
