#include<bits/stdc++.h>

using namespace std;

int dp[1001][11];

void DP(int n)
{
	for(int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	for(int i = 2; i <= n; i++)
	{
		dp[i][1] = 1;
		for(int j = 0; j < 10; j++)
		{
			dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	DP(n);

	int ans = 0;
	for(int i = 0; i < 10; i++)
	{
		ans = (ans + dp[n][i]) % 10007;
	}

	cout << ans;

	return 0;
}