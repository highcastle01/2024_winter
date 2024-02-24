#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int n; cin >> n;

	if(n % 2)
	{
		for(int i = 0; i < n / 2; i++)
		{
			cout << 1 << " " <<  2 << " ";
		}
		cout << 3;
	}
	else
	{
		for(int i = 0; i < n / 2; i++)
		{
			cout << 1 << " " <<  2 << " ";
		}
	}
	return 0;
}