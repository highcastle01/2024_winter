#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, t;
int board[301][301];

void floyd()
{
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				board[i][j] = min(board[i][j], max(board[i][k], board[k][j]));
			}
		}
	}
}

void check(int start, int end)
{
	int ans = (board[start][end] == INF) ? -1 : board[start][end];
	cout << ans << "\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			board[i][j] = (i == j) ? 0 : INF;
		}
	}

	for(int i = 0; i < m; i++)
	{
		int u, v, h; cin >> u >> v >> h;

		board[u][v] = h;
	}

	floyd();

	for(int i = 0; i < t; i++)
	{
		int x, y; cin >> x >> y;

		check(x, y);
	}

	return 0;
}