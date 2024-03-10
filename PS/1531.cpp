#include<bits/stdc++.h>

using namespace std;

int n, m;
int board[101][101];

int main(void)
{
	cin >> n >> m;
	int maxX = 0;
	int maxY = 0;
	int cnt = 0;

	for(int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		maxX = max(x2, maxX);
		maxY = max(y2, maxY);

		for(int j = x1; j <= x2; j++)
		{
			for(int k = y1; k <= y2; k++)
			{
				board[j][k]++;
			}
		}
	}

	for(int i = 1; i <= maxX; i++)
	{
		for(int j = 1; j <= maxY; j++)
		{
			if(board[i][j] > m)
			{
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}