#include<bits/stdc++.h>

using namespace std;

int dp[11];

void DP(int n)
{
	dp[1] = 0;
	dp[2] = 1;

	for(int i = 3; i <= n; i++)
	{
		int div = i / 2;
		dp[i] = (div * (i - div)) + dp[div] + dp[i-div];
		
	}
}

int main(void)
{
	int n; cin >> n;

	DP(n);

	cout << dp[n];

	return 0;
}