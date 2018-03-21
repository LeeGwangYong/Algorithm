#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int n, m; //1 <= n, m <= 300
	scanf("%d %d", &n, &m);
	printf("%d\n", (n-1)+n*(m-1));
	return 0;
}