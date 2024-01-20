#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int n;

int board[51][51];
int man[51][3]; // 열 : 준개수 / 받을개수 / 선물지수
int nexts[51];

vector<string> friends = {"joy", "brad", "alessandro", "conan", "david"};
vector<string> gifts = {"alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"};

int check(int n)
{
    //give
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == INF)
            {
                continue;
            }
            man[i][0] += board[i][j];
        }
    }
    
    //receive
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(board[i][j] == INF)
            {
                continue;
            }
            man[j][1] += board[i][j];
        }
    }
    
    //rate
    
    for(int i = 0; i < n; i++)
    {
        man[i][2] = man[i][0] - man[i][1];
    }
    
    //receive2222
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] > board[j][i])
            {
                nexts[i] += 1;
            }
            else if(board[i][j] == 0 && board[j][i] == 0)
            {
                if(man[i][2] > man[j][2])
                {
                    nexts[i] += 1;
                }
            }
            else if(board[i][j] == board[j][i])
            {
                if(man[i][2] > man[j][2])
                {
                    nexts[i] += 1;
                }
            }
        }
    }
    
    int ans = 0;
    
    //end
    for(int i = 0; i < n; i++)
    {
        ans = max(nexts[i], ans);
    }
    
    return ans;
}

int solution(vector<string> friends, vector<string> gifts)
{
    n = friends.size();
    int m = gifts.size();
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                board[i][j] = INF;
            }
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            string giver, receiver;
            int idx = 0;
            bool flag = false;
            for(auto c : gifts[j]) 
            {
                if(c == ' ')
                {
                    flag = true;
                }
                if(!flag)
                {
                    giver += c;
                }
                else
                {
                    if(c != ' ')
                    {
                        receiver += c;
                    }
                }
            }
            if(giver == friends[i])
            {
                for(int k = 0; k < n; k++)
                {
                    if(receiver == friends[k])
                    {
                        idx = k;
                    }
                }
                board[i][idx] += 1;
            }
        }
    }
    
    return check(n);
}

int main(void)
{
    cout << solution(friends, gifts);

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n Man \n";

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < 3; j++)
    //     {
    //         cout << man[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n next \n";

    // for(int i = 0; i < n; i++)
    // {
    //     cout << nexts[i] << " ";
    // }
    return 0;
}