#include<bits/stdc++.h>

using namespace std;

int n, m;
int board[1001][1001];
bool vis[1001][1001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = true;

	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second; q.pop();

		for(int dir = 0; dir < 4; dir++)
		{
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			if(nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue;
			}
			if(!vis[nx][ny] && board[nx][ny])
			{
				q.push({nx, ny});
				vis[nx][ny] = true;
			}
		}
	}
}

void DFS(int x, int y)
{
	vis[x][y] = true;

	for(int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if(nx < 0 || nx >= n || ny < 0 || ny >= m)
		{
			continue;
		}

		if(!vis[nx][ny] && !board[nx][ny])
		{
			DFS(nx, ny);
		}
	}
}

int main(void)
{
	cin >> n >> m;
	int cnt = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int r, g, b; cin >> r >> g >> b;
			board[i][j] = (r+g+b)/3;
		}
	}

	int t; cin >> t;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(board[i][j] >= t)
			{
				board[i][j] = 255;
			}
			else
			{
				board[i][j] = 0;
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(!vis[i][j] && board[i][j])
			{
				BFS(i, j);
				// DFS(i, j);
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}