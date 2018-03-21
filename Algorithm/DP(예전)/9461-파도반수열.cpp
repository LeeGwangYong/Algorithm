#include <iostream>
#include <algorithm>
using namespace std;

long long dp[101];

int main()
{
	int t, n;
	scanf("%d", &t);

	dp[1] = 1;
	dp[2] = dp[1];
	dp[3] = dp[2];
	dp[4] = dp[1] + dp[3];
	dp[5] = dp[4];
	dp[6] = dp[3] + dp[5];
	dp[7] = dp[2] + dp[6];
	dp[8] = dp[1] + dp[7];

	for (int i = 0; i < t; i++){
		scanf("%d", &n);
		for (int j = 9; j <= n; j++) {
			dp[j] = dp[j - 5] + dp[j - 1];
		}
		printf("%lld\n", dp[n]);
	}

	
	return 0;
}