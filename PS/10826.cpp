#include<bits/stdc++.h>

using namespace std;

string dp[10001];

string sum(string a, string b)
{
	int num = 0;
	int carry = 0;
	string res = "";

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while(a.size() < b.size())
	{
		a += "0";
	}

	while(a.size() > b.size())
	{
		b += "0";
	}

	for(int i = 0; i < a.size(); i++)
	{
		num = ((a[i] - '0') + (b[i] - '0') + carry) % 10;
		res += to_string(num);
		carry = ((a[i] - '0') + (b[i] - '0') + carry) / 10;
	}

	if(carry != 0)
	{
		res += to_string(carry);
	}

	reverse(res.begin(), res.end());

	return res;
}

void DP(int n)
{
	dp[0] = "0";
	dp[1] = "1";

	for(int i = 2; i <= n; i++)
	{
		dp[i] = sum(dp[i-2], dp[i-1]);
	}
} 

int main(void)
{
	int n; cin >> n;

	DP(n);

	cout << dp[n];
	return 0;
}