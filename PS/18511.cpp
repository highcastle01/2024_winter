#include<bits/stdc++.h>

using namespace std;

int klist[3];
int n, k, ans;

void solution(int x, int ten)
{
	if(x > n)
	{
		return;
	}

	ans = max(ans, x);

	for(int i = 0; i < k; i++)
	{
		solution(x+klist[i]*ten, ten*10);
	}
}

int main(void)
{
	cin >> n >> k;

	for(int i = 0; i < k; i++)
	{
		cin >> klist[i];
	}

	solution(0, 1);

	cout << ans;

	return 0;
}