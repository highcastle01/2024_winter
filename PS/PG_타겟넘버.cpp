#include <string>
#include <vector>

using namespace std;

int ans;

void DFS(int x, int n, vector<int> numbers, int target)
{
    if(n >= numbers.size())
    {
        if(x == target)
        {
            ans++;
        }
        return;
    }
    
    DFS(x + numbers[n], n + 1, numbers, target);
    DFS(x - numbers[n], n + 1, numbers, target);
}

int solution(vector<int> numbers, int target) 
{
    DFS(numbers[0], 1, numbers, target);
    DFS(numbers[0]*-1, 1, numbers, target);
    return ans;
}