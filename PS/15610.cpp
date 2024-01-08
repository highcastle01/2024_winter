#include<bits/stdc++.h>

using namespace std;

double binarySearchSqrt(double x, double epsilon = 1e-6)
{
	if(x < 0)
	{
		return NAN;
	}

	double low = 0.0, high = x, mid = 0.0;

	while(high - low > epsilon)
	{
		mid = low + (high - low) / 2;

		double squre = mid * mid;

		if(squre < x)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}

	return mid;
}

int main(void)
{
	double n; cin >> n;

	// double ans = binarySearchSqrt(n) * 4;

	double ans = sqrt(n) * 4;

	printf("%.8f", ans);

	return 0;
}