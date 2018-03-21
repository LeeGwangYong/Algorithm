#include <iostream>
#include <algorithm>
using namespace std;
//а╤гу
int money[101];
int dp[10001];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &money[i]);
	}

	dp[0] = 1;
	for (int i = 0; i <= n; i ++ ) {
		for (int j = money[i]; j <= k; j++) {
			dp[j] += dp[j - money[i]];
		}
	}

	printf("%d\n", dp[k]);
	
	return 0;
}