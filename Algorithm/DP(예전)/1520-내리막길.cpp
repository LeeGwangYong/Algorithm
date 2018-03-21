#include <iostream>
#include <algorithm>
using namespace std;

int map[501][501];
int n, m; // n : 가로의 크기, m : 세로의 크기
int cnt = 0;

void function(int i, int j)
{
	if (map[i][j] == map[m][n]) {
		cnt++;
		return;
	}
	if (map[i][j] > map[i - 1][j] && map[i - 1][j] != 0) function(i - 1, j);//상
	if (map[i][j] > map[i + 1][j] && map[i + 1][j] != 0) function(i + 1, j);//하
	if (map[i][j] > map[i][j - 1] && map[i][j - 1] != 0) function(i, j - 1);//좌
	if (map[i][j] > map[i][j + 1] && map[i][j + 1] != 0) function(i, j + 1);//우
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