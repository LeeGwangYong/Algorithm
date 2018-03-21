#include<iostream>
using namespace std;
#include<algorithm>

int stair[301];
int dp[301][3];


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &stair[i]);
	}
	
	dp[1][1] = stair[1];
	dp[2][0] = stair[1];
	dp[2][1] = stair[2];
	dp[2][2] = dp[1][1] + stair[2];

	for (int i = 3; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + stair[i];
		dp[i][2] = dp[i - 1][1] + stair[i];
	}
	
	printf("%d\n", max(dp[n][1], dp[n][2]));

	return 0;
}