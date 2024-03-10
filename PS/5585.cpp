#include<bits/stdc++.h>

using namespace std;

int coins[6] = {500, 100, 50, 10, 5, 1};

int main(void)
{
	int c; cin >> c;
	int cnt = 0;
	int jandon = 1000 - c;

	cnt += (jandon / coins[0]);
	cnt += (jandon % coins[0]) / coins[1];
	cnt += ((jandon % coins[0]) % coins[1]) / coins[2];
	cnt += (((jandon % coins[0]) % coins[1]) % coins[2]) / coins[3];
	cnt += ((((jandon % coins[0]) % coins[1]) % coins[2]) % coins[3]) / coins[4];
	cnt += (((((jandon % coins[0]) % coins[1]) % coins[2]) % coins[3]) % coins[4]) / coins[5];

	cout << cnt;

	return 0;
}