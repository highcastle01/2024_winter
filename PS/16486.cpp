#include<bits/stdc++.h>

using namespace std;

const double pi = 3.141592;

int main(void)
{
	int d1, d2; cin >> d1 >> d2;

	double ans = d1*2 + 2*pi*d2;

	printf("%.6f", ans);

	return 0;
}