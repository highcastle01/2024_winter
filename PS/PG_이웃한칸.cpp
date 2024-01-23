#include <string>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int solution(vector<vector<string>> board, int h, int w) 
{
    int n = board.size();
    int cnt = 0;
    for(int dir = 0; dir < 4; dir++)
    {
        int nx = h + dx[dir];
        int ny = w + dy[dir];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
        {
            continue;
        }

        if(board[h][w] == board[nx][ny])
        {
            cnt++;
        }
    }

    return cnt;
}