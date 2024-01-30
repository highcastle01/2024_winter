#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

string ans;
int lefth = 10;
int righth = 11;

void left(int cur)
{
    lefth = cur;
    ans.push_back('L');
}

void right(int cur)
{
    righth = cur;
    ans.push_back('R');
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int board[4][3] = {
    {1, 2, 3}, 
    {4, 5, 6}, 
    {7, 8, 9}, 
    {10, 0, 11}
};

int find(int x, int y, int find)
{
    bool vis[4][3];
    int dist[4][3];
    memset(vis, false, sizeof(vis));
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    vis[x][y] = true;
    q.push({x, y});
    int cnt = 0;
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir]; //세로
            int ny = cur.second + dy[dir]; //가로

            if(nx < 0 || nx >= 4 || ny < 0 || ny >= 3)
            {
                continue;
            }
            if(!vis[nx][ny])
            {
                vis[nx][ny] = true;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                q.push({nx, ny});
                if(board[nx][ny] == find)
                {
                    return dist[nx][ny];
                }
            }
        }
    }
    return -1;
}

bool check(int cur, string hand) //0이면 left, 1이면 right
{
    if(cur == 2 || cur == 5 || cur == 8 || cur == 0)
    {
        int lcur = 0;
        int rcur = 0;
        int leftx, lefty, rightx, righty;
        
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == lefth)
                {
                    leftx = i;
                    lefty = j;
                }
                if(board[i][j] == righth)
                {
                    rightx = i;
                    righty = j;
                }
            }
        }
        if(find(leftx, lefty, cur) < find(rightx, righty, cur))
        {
            return false;
        }
        else if(find(leftx, lefty, cur) == find(rightx, righty, cur))
        {
            if(hand == "left")
            {
                return false;
            }
            else if(hand == "right")
            {
                return true;
            }
        }
        else if(find(leftx, lefty, cur) > find(rightx, righty, cur))
        {
            return true;
        }
    }
    else if(cur == 1 || cur == 4 || cur == 7)
    {
        return false;
    }
    else if(cur == 3 || cur == 6 || cur == 9)
    {
        return true;
    }
}

string solution(vector<int> numbers, string hand) 
{
    for(int i = 0; i < numbers.size(); i++)
    {
        if(!check(numbers[i], hand)) // left
        {
            left(numbers[i]);
        }
        else // right
        {
            right(numbers[i]);
        }
    } 
    return ans;
}

int main(void)
{
    vector<int> numbers = {
        7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2
    };
    string hand = "left";
    cout << solution(numbers, hand);
    return 0;
}