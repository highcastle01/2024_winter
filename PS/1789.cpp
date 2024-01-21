#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	long long s; cin >> s;
	long long cur = 0;
	long long check = 0;

	while(check != s)
	{
		if(check > s)
		{
			cur--;
			break;
		}
		cur++;
		check += cur;
	}

	cout << cur;

	return 0;
}