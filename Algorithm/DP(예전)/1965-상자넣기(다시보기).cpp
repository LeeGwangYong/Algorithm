#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int sum[1001];

int main()
{
	int n;
	int m;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dp[i]);
	}	

	for (int i = 1; i <= n; i++) {
		sum[i] = 1;
		for (int j = 1; j <= n; j++) {
			if (dp[i] > dp[j] && sum[i] < sum[j] + 1) sum[i] = sum[j] + 1;
		}
	}

	m = sum[1];

	for (int i = 1; i <= n; i++) {
		m = max(m, sum[i]);
	}

	printf("%d\n", m);

	return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;
vector<int> lis;
int n;

int main() {
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	lis.push_back(v[0]);
	for (int i = 1; i < n; i++) {
		if (lis.back() < v[i]) {
			lis.push_back(v[i]);
		}
		else {
			vector<int>::iterator iter = lower_bound(lis.begin(), lis.end(), v[i]);
			*iter = v[i];
		}
	}

	cout << lis.size();
	return 0;
}
*/