#include<bits/stdc++.h>

using namespace std;

int sam[3];

void change()
{
	if(sam[2] >= sam[1] + sam[0])
	{
		sam[2] = sam[1] + sam[0] - 1;
	}

	cout << sam[2] + sam[1] + sam[0];
}

int main(void)
{
	int a, b, c; cin >> a >> b >> c;
	sam[0] = a;
	sam[1] = b;
	sam[2] = c;

	sort(sam, sam+3);

	change();

	return 0;
}