#include <string>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int n, m;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int board[501][501];
bool vis[501][501];
int oil[501];

void makeBoard(vector<vector<int>> land)
{
    for(int i = 0; i < land.size(); i++)
    {
        for(int j = 0; j < land[i].size(); j++)
        {
            board[i][j] = land[i][j];
        }
    }
}

void BFS(int x, int y, int n, int m)
{
    queue<pair<int, int>> q;
    vis[x][y] = 1;
    q.push({x, y});
    int up = y, down = y;
    
    int cnt = 0;
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        up = min(up, cur.Y);
        down = max(down, cur.Y);

        cnt++;
        
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }
            if(!vis[nx][ny] && board[nx][ny] == 1)
            {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }

    for(int i = up; i <= down; i++)
    {
        oil[i] += cnt;
    }
}

int solution(vector<vector<int>> land)
{
    makeBoard(land);
    
    n = land.size();
    m = land[0].size();
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 1 && !vis[i][j])
            {
                BFS(i, j, n, m);
            }
        }
    }
    
    int ans = 0;
    
    for(int i = 0; i < m; i++)
    {
        ans = max(ans, oil[i]);
    }
    
    return ans;
}