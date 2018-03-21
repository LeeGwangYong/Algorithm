#include <iostream>
#include <algorithm>
using namespace std;

int wine[10001];
int dp[10001][3];

int main()
{
	int n, m;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &wine[i+1]);
	}

	dp[1][1] = wine[1];

	for (int i = 1; i < n; i++) {
		dp[i + 1][0] = max(max(dp[i][0], dp[i][1]), dp[i][2]);
		dp[i + 1][1] = dp[i][0] + wine[i+1];
		dp[i + 1][2] = dp[i][1] + wine[i+1];
	}

	printf("%d\n", max(dp[n][0], max(dp[n][1], dp[n][2])));

	return 0;
}