#include <iostream>
#include <algorithm>
using namespace std;
long long dp[31][31];
// 조합 문제

/* 시간초과
long long factorial(int n) {
	if (n == 1) return 1;
	return n*factorial(n-1);
}
*/

/* 시간초과
long long combination(int n, int r) {
	if (n == r || r == 0) return 1;
	return combination(n - 1, r - 1) + combination(n - 1, r);
}
*/
void input(int n, int r)
{
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i < n; i ++ ) {
		for (int j = 1; j < r; j++) {
			if (i == j) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
}

int main()
{
	int n, m;// 0<n<=m<30
	int t;
	scanf("%d", &t);
	input(31, 31);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		printf("%lld\n", dp[m][n]);
		//printf("%lld\n", combination(m, n));
		//printf("%lld\n", factorial(m) / ( factorial(n) * factorial(m - n) ) );
	}
	return 0;
}