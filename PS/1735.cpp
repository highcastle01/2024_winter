#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

int main(void)
{
	int a, b, c, d; cin >> a >> b >> c >> d;

	int mo = b*d;
	int ja = a*d + c*b;

	int gcds = gcd(mo, ja);

	cout << ja / gcds << " " << mo / gcds;

	return 0;
}