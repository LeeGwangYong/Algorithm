#include <iostream>
#include<algorithm>
using namespace std;
int arr[501][501];
int dp[501][501];

void function(int n, int m) {
	if(arr[n][m] < arr[n-1][m]) // ��
	if(arr[n][m] < arr[n+1][m]) // ��
	if(arr[n][m] < arr[n][m+1]) // ��
	if(arr[n][m] < arr[n][m-1]) // ��
}

int main()
{
	int n; //1<=n<=500
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	
	return 0;
}
