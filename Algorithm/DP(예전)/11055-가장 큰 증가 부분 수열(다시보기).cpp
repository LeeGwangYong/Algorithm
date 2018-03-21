#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;
typedef long long ll;
ll dp[1001];
ll sum[1001];


void function(int n) {
	for (int i = 1; i <= n; i++) {
		sum[i] = dp[i]; //sum[i] �� i���縦 �����ϴ� �κм����� ���� ū��
		for (int j = 1; j < i; j++) {
			if ( dp[i] > dp[j]) {
				sum[i] = max(dp[i] + sum[j], sum[i]);
			}
		}

	}
}


void max_func(int n) {
	ll tmp;
	tmp = sum[1];
	for (int i = 1; i <= n; i++) {
		tmp = max(tmp, sum[i]);
	}

	printf("%lld\n", tmp);
}

int main()
{
	int n;
	
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &dp[i]);
	}
	


	function(n);
	max_func(n);
	

	return 0;
}