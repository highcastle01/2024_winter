#include<bits/stdc++.h>

using namespace std;

int items[101];
int board[101][101];
int d[101][101];
int n, m, r;

const int INF = 0x3f3f3f;

void floyd()
{
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(board[i][j] > board[i][k] + board[k][j])
				{
					board[i][j] = board[i][k] + board[k][j];
				}
			}
		}
	}
}

int check()
{
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int cnt = items[i];
		for(int j = 1; j <= n; j++)
		{
			if(i != j && board[i][j] <= m)
			{
				cnt += items[j];
			}
		}
		ans = max(ans, cnt);
	}

	return ans;
}

int main(void)
{
	cin >> n >> m >> r;

	for(int i = 1; i <= n; i++)
	{
		cin >> items[i];
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			board[i][j] = INF;
			if(i == j)
			{
				board[i][j] = 1;
			}
		}
	}

	for(int i = 0; i < r; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		board[u][v] = w;
		board[v][u] = w;
	}

	floyd();

	cout << check();

	return 0;
}