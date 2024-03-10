#include<bits/stdc++.h>

using namespace std;

int a, k, cnt;

int dp[1000001];

int BFS()
{
	queue<int> q;
	q.push(a);

	while(!q.empty())
	{
		int cur = q.front(); q.pop();

		if(cur == k)
		{
			return dp[cur];
		}

		int first = cur + 1;
		int second = cur * 2;

		if(first <= 1000001 && !dp[first])
		{
			q.push(first);
			dp[first] = dp[cur] + 1;
		}
		if(second <= 1000001 && !dp[second])
		{
			q.push(second);
			dp[second] = dp[cur] + 1;
		}
	}
}

int DP()
{
	for(int i = a+1; i <= k; i++)
	{
		dp[i] = dp[i-1] + 1;
		if(i % 2 == 0 && i / 2 >= a)
		{
			dp[i] = min(dp[i], dp[i/2] + 1);
		}
	}

	return dp[k];
}

int main(void)
{
	cin >> a >> k;

	cout << BFS();
	//cout << DP();
	return 0;
}