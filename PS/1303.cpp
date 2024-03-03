#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int n, m;
int board[101][101];
bool vis[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


void makeBoard(vector<string> maps)
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(maps[i][j] == 'W')
			{
				board[i][j] = 0;
			}
			else if(maps[i][j] == 'B')
			{
				board[i][j] = 1;
			}
		}
	}
}

// 0은 w, 1은 b
int BFS(int x, int y, bool color)
{
	queue<pair<int, int>> q;
	vis[x][y] = true;
	q.push({x, y});
	int cnt = 1;

	while(!q.empty())
	{
		auto cur = q.front(); q.pop();

		for(int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if(nx < 0 || nx >= m || ny < 0 | ny >= n)
			{
				continue;
			}

			if(!vis[nx][ny] && board[nx][ny] == color)
			{
				cnt++;
				q.push({nx, ny});
				vis[nx][ny] = true;
			}

		}
	}

	return cnt * cnt;
}

int DFS(int x, int y, int cnt, bool color)
{
	vis[x][y] = true;
	for(int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if(nx < 0 || nx >= m || ny < 0 | ny >= n)
		{
			continue;
		}

		if(!vis[nx][ny] && board[nx][ny] == color)
		{
			cnt = DFS(nx, ny, cnt+1, color);
		}
	}

	return cnt;
}

int main(void)
{
	cin >> n >> m;
	vector<string> maps;

	for(int i = 0; i < m; i++)
	{
		string str; cin >> str;
		maps.push_back(str);
	}

	makeBoard(maps);

	
	int wcnt = 0, bcnt = 0;
	//// BFS
	// for(int i = 0; i < m; i++)
	// {
	// 	for(int j = 0; j < n; j++)
	// 	{
	// 		if(!vis[i][j] && !board[i][j])
	// 		{
	// 			wcnt += BFS(i, j, 0);
	// 		}
	// 	}
	// }

	// memset(vis, 0, sizeof(vis));

	// for(int i = 0; i < m; i++)
	// {
	// 	for(int j = 0; j < n; j++)
	// 	{
	// 		if(!vis[i][j] && board[i][j])
	// 		{
	// 			bcnt += BFS(i, j, 1);
	// 		}
	// 	}
	// }

	// DFS
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(!vis[i][j] && !board[i][j])
			{
				int tmp = DFS(i, j, 1, 0);
				wcnt += tmp * tmp;
			}
		}
	}

	memset(vis, 0, sizeof(vis));

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(!vis[i][j] && board[i][j])
			{
				int tmp = DFS(i, j, 1, 1);
				bcnt += tmp * tmp;
			}
		}
	}


	cout << wcnt << " " << bcnt;

	return 0;
}