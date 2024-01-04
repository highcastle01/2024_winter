#include<bits/stdc++.h>

using namespace std;

void check(int arr[])
{
	if(arr[2] >= arr[1] + arr[0])
	{
		cout << "Invalid\n"; 
	}
	else if(arr[0] == arr[1] && arr[1] == arr[2])
	{
		cout << "Equilateral\n";
	}
	else if(arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2])
	{
		cout << "Isosceles\n";
	}
	else if(arr[0] != arr[1] && arr[1] != arr[2])
	{
		cout << "Scalene\n";
	}
}

int main(void)
{
	while(1)
	{
		int a, b, c; cin >> a >> b >> c;

		if(a == 0 && b == 0 && c == 0)
		{
			break;
		}

		int arr[3];

		arr[0] = a;
		arr[1] = b;
		arr[2] = c;

		sort(arr, arr + 3);

		check(arr);
	}

	return 0;
}