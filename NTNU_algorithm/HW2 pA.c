#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int m = n / 2;
    // int dp[m + 1];
    int* dp = malloc(sizeof(int) * (m + 1));
    // number of ways to make i coins by 1 coin.
    for(int i = 0; i <= m; i++)
        dp[i] = 1;
    // update number of ways to make i coins by 2, 4, 8, 16, ... coins.
    for(int coin = 2; n/coin > 0; coin *= 2){
        for(int i = coin/2; i <= m; i++)
            dp[i] = (dp[i] + dp[i - coin/2]) % (int)(1e9+7);
    }
    printf("%d\n", dp[m]);
    return 0;
}
