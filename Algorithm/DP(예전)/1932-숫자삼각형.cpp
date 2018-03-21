#include<iostream>
#include<algorithm>
using namespace std;

int dp[501][501];
void function(int i, int j) {
	dp[i][j] = dp[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
}
int main()
{
	int n, number;
	int m;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &number);
			dp[i][j] = number;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			function(i, j);
		}
	}

	m = dp[n][1];
	for (int i = 1; i <= n; i++) {
		m = max(m, dp[n][i]);
	}

	printf("%d\n", m);

	return 0;
}
/*
int function(int i, int j) {
	if (dp[i+1][j] == 0) return dp[i][j];

	int left_child = dp[i+1][j];
	int right_child = dp[i+1][j+1];

	if (left_child > right_child) function(i + 1, j);
	else if(left_child < right_child) function(i + 1,j + 1);

	return dp[i][j] = dp[i][j]+max(dp[i+1][j], dp[i+1][j+1]);
	//return function(i,j) + max(left_child, right_child);//dp[i][j]¸¦ function(i,j)·Î?
}

int main()
{
	int n, number;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &number);
			dp[i][j] = number;
		}
	}

	printf("%d\n", function(1,1));
	
	return 0;
}
*/