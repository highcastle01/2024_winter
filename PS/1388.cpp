#include<bits/stdc++.h>

using namespace std;

int n, m;

bool lvis[51][51];
bool cvis[51][51];

string board[51];

void Low(int x, int y)
{
	for(int dir = 0; dir < m; dir++)
	{
		if(board[x][y+dir] != '-')
		{
			break;
		}
		lvis[x][y+dir] = true;
	}
}

void Col(int x, int y)
{
	for(int dir = 0; dir < n; dir++)
	{
		if(board[x+dir][y] != '|')
		{
			break;
		}
		cvis[x+dir][y] = true;
	}
}

int main(void)
{
	cin >> n >> m;
	int lcnt = 0, ccnt = 0;

	for(int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(!lvis[i][j] && board[i][j] == '-')
			{
				Low(i, j);
				lcnt++;
			}
			if(!cvis[i][j] && board[i][j] == '|')
			{
				Col(i, j);
				ccnt++;
			}
		}
	}

	cout << lcnt + ccnt;

	return 0;
}