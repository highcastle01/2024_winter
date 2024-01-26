#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int n; cin >> n;
	int cnt = 0;

	//윗칸이 아랫칸이랑 개수가 같을 때 까지 반복
	//아랫칸은 i, 윗칸은 j반복문에서 처리하는 셈
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			cnt += i + j;
		}
	}

	cout << cnt;

	return 0;
}