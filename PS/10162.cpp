#include<bits/stdc++.h>

using namespace std;

int button[3] = {300, 60, 10};

int main(void)
{
	int a, b, c = 0;
	int t; cin >> t;

	if(t % 10)
	{
		cout << -1;
	}
	else
	{
		a = t / button[0];
		b = (t % button[0]) / button[1];
		c = ((t % button[0]) % button[1]) / button[2];
		cout << a << " " << b << " " << c;
	}
	return 0;
}