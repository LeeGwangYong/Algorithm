#include <iostream>
#include <algorithm>
using namespace std;

int num[100010];
int dp[100010];

int main()
{
	int n;
	int m=0;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (dp[i - 1] + num[i] > num[i]) dp[i] = dp[i - 1] + num[i];
		else dp[i] = num[i];
	}
	m = dp[1];

	for (int i = 2; i <= n; i++) {
		m = max(m, dp[i]);
	}

	printf("%d\n", m);

	return 0;
}
/* 시간초과
int dp[100001];
int m = 0;

void function(int i_, int n) {
	
	int cnt=i_;
	int sum=0;
	if (i_ > n) return;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < cnt; j++) {
			sum = sum + dp[i+j];
		}
		m = max(m, sum);
		sum = 0;
	}

	function(i_+1,n);
}
int main()
{
	int n, num; // 1<=n<=100000, -1000<=m<=1000

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		dp[i] = num;
	}
	m = dp[1];
	function(1, n);
	printf("%d\n", m);

	return 0;
}
*/