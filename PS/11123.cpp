#include<bits/stdc++.h>

using namespace std;

int board[101][101];
bool vis[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int x, int y, int h, int w)
{
	queue<pair<int,int>> q;
	vis[x][y] = true;
	q.push({x, y});

	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second; q.pop();

		for(int dir = 0; dir < 4; dir++)
		{
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			if(nx < 0 || nx >= h || ny < 0 || ny >= w)
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

void DFS(int x, int y, int h, int w)
{
	vis[x][y] = true;

	for(int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if(nx < 0 || nx >= h || ny < 0 || ny >= w)
		{
			continue;
		}
		if(!vis[nx][ny] && board[nx][ny])
		{
			DFS(nx, ny, h, w);
		}
	}
}

int main(void)
{
	int t; cin >> t;

	while(t--)
	{
		int h, w; cin >> h >> w;
		int cnt = 0;
		memset(board, 0, sizeof(board));
		memset(vis, 0, sizeof(vis));

		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				char x; cin >> x;
				if(x == '#')
				{
					board[i][j] = 1;
				}
				if(x == '.')
				{
					board[i][j] = 0;
				}
			}
		}

		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				if(!vis[i][j] && board[i][j])
				{
					// BFS(i, j, h, w);
					DFS(i, j, h, w);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}