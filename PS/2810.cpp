#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int n; cin >> n;
	int man = 0, cup = 0;
	map<char, int> m;

	for(int i = 0; i < n; i++)
	{
		char c; cin >> c;
		m[c]++;
	}

	man = m['S'] + m['L'];
	cup = m['S'] + m['L']/2 + 1;

	if(cup <= man)
	{
		cout << cup;
	}
	else
	{
		cout << man;
	}

	return 0;
}