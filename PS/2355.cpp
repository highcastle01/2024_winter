#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	long long a, b; cin >> a >> b;

	if(a > b)
	{
		swap(a, b);
	}

	long long ans = (b-a+1)*(b+a)/2;

	cout << ans;

	return 0;
}