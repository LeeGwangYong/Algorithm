#include <iostream>
#include <algorithm>
using namespace std;

long long dp_min[2][3];
long long dp_max[2][3];

void function_min(int a, int b, int c)
{
	dp_min[1][0] = min(dp_min[0][0], dp_min[0][1]) + a;
	dp_min[1][1] = min(min(dp_min[0][0], dp_min[0][1]), dp_min[0][2]) + b;
	dp_min[1][2] = min(dp_min[0][1], dp_min[0][2]) + c;

	dp_min[0][0] = dp_min[1][0];
	dp_min[0][1] = dp_min[1][1];
	dp_min[0][2] = dp_min[1][2];
}

void function_max(int a, int b, int c) {
	dp_max[1][0] = max(dp_max[0][0], dp_max[0][1]) + a;
	dp_max[1][1] = max(max(dp_max[0][0], dp_max[0][1]), dp_max[0][2]) + b;
	dp_max[1][2] = max(dp_max[0][1], dp_max[0][2]) + c;

	dp_max[0][0] = dp_max[1][0];
	dp_max[0][1] = dp_max[1][1];
	dp_max[0][2] = dp_max[1][2];
}

int main()
{
	int n, a, b, c;
	long long val_max, val_min;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (i == 0) {
			dp_max[0][0] = a; dp_max[0][1] = b; dp_max[0][2] = c;
			dp_min[0][0] = a; dp_min[0][1] = b; dp_min[0][2] = c;
		}
		else{
			function_max(a, b, c);
			function_min(a, b, c);
		}
	}

	val_max = max(max(dp_max[0][0], dp_max[0][1]), dp_max[0][2]); //n = 1일 때를 생각해줘야하므로 dp_max[0][] 이 올바르다.
	val_min = min(min(dp_min[0][0], dp_min[0][1]), dp_min[0][2]);

	printf("%lld %lld\n", val_max, val_min );

	return 0;
}