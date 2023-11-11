#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define ll long long

int cmpfunc(const void* a, const void* b){
    return (*(ll*)a - *(ll*)b);
}

int main(){
    int n;
	scanf("%d", &n);
    ll arr[n];
	ll dp[n+1][n+1];
    // initialize dp[i][i] = arr[i]
	for(int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
    qsort(arr, n, sizeof(ll), cmpfunc);

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = LLONG_MAX;

    // init cases of one node and two nodes 
    for(int i = 1; i <= n; i++){
        dp[i][i] = arr[i-1];
        if(i < n)
            dp[i][i+1] = arr[i-1] + arr[i];
    }

    for(int len = 3; len <= n; len++){
        for(int i = 1; i <= n - len + 1; i++){
            int j = i + len - 1;
            // where i < k < j
            for(int k = i+1; k < j; k++){
                // dp[i][j] = min(dp[k][k] + max (dp[i][k-1] + dp[k+1][j]))
                ll val = dp[k][k];
                val += max (dp[i][k-1], dp[k+1][j]);
                dp[i][j] = min(dp[i][j], val);
            }
        }
    }

    printf("%lld\n", dp[1][n]);
    return 0;
}
