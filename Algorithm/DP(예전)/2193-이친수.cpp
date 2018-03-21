#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dp[91];

ll function(int n) {
	if (dp[n] != 0)	return dp[n]; // 이게 왜 중요할까

	if (n == 0) return 0;
	else if (n == 1) return dp[n] = 1;
	else if (n == 2) return dp[n] = 1;
	else return dp[n] = function(n - 1) + function(n - 2);
}

int main()
{
	int n;
	scanf("%d", &n);
	function(n);
	printf("%lld\n", dp[n]);
	return 0;
}

/* 시간초과(트리형)
#define INF 987654321
int dp[91];
int cnt=0;

void function(int n) {

	if (n == 1) {
		if (dp[2] == 0) {
			cnt = cnt + 2;
			return;
		}
		else {
			cnt++;
			return;
		}
	}
	else if (n == 0 || n == 10) return;
	else {
		if (dp[n + 1] == INF) {
			dp[n] = 1;
			function(n - 1);
		}

		else if (dp[n + 1] == 1) {
			dp[n] = 0;
			function(n - 1);
		}

		else if (dp[n + 1] == 0) {
			dp[n] = 0;
			function(n - 1);

			dp[n] = 1;
			function(n - 1);
		}
	}
}

int main()
{
	int N;
	
	scanf("%d", &N);
	dp[N+1] = INF;
	function(N);
	printf("%d\n", cnt);
	return 0;
}
*/