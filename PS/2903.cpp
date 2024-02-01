#include<bits/stdc++.h>

using namespace std;

int solution(int n)
{
	int dot = 2;
	for(int i = 1; i < pow(2, n); i*=2)
	{
		dot += i;
	}

	return dot * dot;
}

int main(void)
{
	int n; cin >> n;

	cout << solution(n);

	return 0;
}