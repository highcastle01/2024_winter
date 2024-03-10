#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int a, b, c;
	while(cin >> a >> b >> c)
	{
		int jump = max(b-a, c-b) - 1;
		cout << jump << "\n";
	}
	return 0;
}