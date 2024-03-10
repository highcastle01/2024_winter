#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	string a, b; cin >> a >> b;
	string as = a, bs = b, ab = a, bb = b;

	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] == '5')
		{
			ab[i] = '6';
		}
		if(a[i] == '6')
		{
			as[i] = '5';
		}
	}

	for(int i = 0; i < b.size(); i++)
	{
		if(b[i] == '5')
		{
			bb[i] = '6';
		}
		if(b[i] == '6')
		{
			bs[i] = '5';
		}
	}

	int small = stoi(as) + stoi(bs);
	int big = stoi(ab) + stoi(bb);
	
	cout << small << " " << big;

	return 0;
}