#include<bits/stdc++.h>

using namespace std;

int check[51];

int main(void)
{
	int n; cin >> n;
	int cnt = 1;

	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		check[x]++;
	}

	for(int i = n; i >= 0; i--)
	{
		if(check[i] == i)
		{
			cout << i;
			return 0;
		}
	}
	cout << "-1" << endl;

	return 0;
}