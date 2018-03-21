#include <iostream>
#include <algorithm>
using namespace std;

int map[501][501];
int n, m; // n : ������ ũ��, m : ������ ũ��
int cnt = 0;

void function(int i, int j)
{
	if (map[i][j] == map[m][n]) {
		cnt++;
		return;
	}
	if (map[i][j] > map[i - 1][j] && map[i - 1][j] != 0) function(i - 1, j);//��
	if (map[i][j] > map[i + 1][j] && map[i + 1][j] != 0) function(i + 1, j);//��
	if (map[i][j] > map[i][j - 1] && map[i][j - 1] != 0) function(i, j - 1);//��
	if (map[i][j] > map[i][j + 1] && map[i][j + 1] != 0) function(i, j + 1);//��
}
int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	function(1, 1);
	printf("%d\n", cnt);
	return 0;
}