#include<bits/stdc++.h>

using namespace std;

long long dp[81];

void DP(int n)
{
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 3; i <= n+1; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
}

int main(void)
{
	long long n; cin >> n;

	DP(n);

	long long ans = dp[n] * 2 + dp[n+1] * 2;

	cout << ans;

	return 0;
}