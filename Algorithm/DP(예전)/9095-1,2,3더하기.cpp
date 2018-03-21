#include <iostream>
#include <algorithm>
using namespace std;

int cnt=0;

void function(int n) {
	if (n == 0) {
		cnt++;
		return;
	}
	if (n < 0)return;
	function(n - 1);
	function(n - 2);
	function(n - 3);
}

int main()
{
	int T, n; // 0<n<11
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &n);
		function(n);
		printf("%d\n", cnt);
		cnt = 0;

	}

	return 0;
}