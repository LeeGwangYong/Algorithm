#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3] = { 0, }; //dp[house_num][rgb°ª]

void function(int house, int r, int g, int b) {
	dp[house][0] = min(dp[house - 1][1], dp[house - 1][2]) + r;
	dp[house][1] = min(dp[house - 1][0], dp[house - 1][2]) + g;
	dp[house][2] = min(dp[house - 1][0], dp[house - 1][1]) + b;
}

int main()
{
	int house_num;
	int R, G, B;
	int minimum;

	scanf("%d", &house_num);

	for (int i = 0; i < house_num; i++) {
		scanf("%d %d %d", &R, &G, &B);
		function(i+1, R, G, B);
	}

	minimum = min(min(dp[house_num][0], dp[house_num][1]), dp[house_num][2]);
	printf("%d\n", minimum);

	return 0;
}
