#include <iostream>
#include <algorithm>
using namespace std;
int price[100001] = {};
int dp[100001] = {};

int main()
{	
	int n;
	scanf("%d", &n);
	for (int i= 1; i <= n; i++) {
		scanf("%d", &price[i]);
	}
// D[N] = MAX(D[N], D[N-K] + P[K])  (P=1~N-1)

	dp[1] = price[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + price[1];
		for (int j = 2; j <= i; j++) {
			dp[i] = max(dp[i - j] + price[j], dp[i]);
		}
	}

	printf("%d\n", dp[n]);

	return 0;
}