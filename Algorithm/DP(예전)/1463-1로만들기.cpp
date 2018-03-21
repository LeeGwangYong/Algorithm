#include <iostream>
#include <algorithm>
using namespace std;
#define INF  987654321

int dp[1000001]; //0��° �ּ� ������ 1���� ������ ���Ͽ�

void function(int N, int count) {
	if (N < 1) { return; }

	int &ret = dp[N];

	if (ret == 0) {
		ret = INF;
	}

	if (ret <= count) return;
	ret = count;

	if (!(N % 3)) { function(N / 3, 1 + count); } // !(N%3)�� N%3 == 0 �� ���� �ǹ�
	if (!(N % 2)) { function(N / 2, 1 + count); }
	function(N - 1, 1 + count);
}


int main()
{
	int N;
	scanf("%d", &N);

	function(N, 0);

	printf("%d\n", dp[1]);

	return 0;
}