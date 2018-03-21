#include <iostream>
#include <algorithm>
using namespace std;
int a[301][301];

void function(int i_in, int j_in, int x, int y)
{
	int sum=0;

	for (int i = i_in; i <= x; i++) {
		for (int j = j_in; j <= y; j++) {
			sum = sum+a[i][j];
		}
	}
	printf("%d\n", sum);
}

int main()
{
	int n, m; // 1<= n,m <=300
	int k; // 1<= k <=10000
	int i_in, j_in, x, y;

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &i_in, &j_in, &x, &y);
		function(i_in, j_in, x, y);
	}
	
	return 0;
}