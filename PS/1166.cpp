#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	long long n, l, w, h; cin >> n >> l >> w >> h;
	double left = 0, right = max(h, max(l, w)), mid;

	for(int i = 0; i < 1000; i++)
	{
		mid = (left + right) / 2; //현재 A의 길이
		if(((long long)(l/mid)) * ((long long)(w/mid)) * ((long long)(h/mid)) < n)
		{//가로*세로*높이가 n보다 작아서 상자에 못넣는다면 상자크기 줄이기.
			right = mid;
		}
		else
		{//가로*세로*높이가 n보다 크거나 같아서 상자에 넣을 수 있으면 상자크기 키우기.
			left = mid;
		}
	}

	printf("%.10lf", left);

	return 0;
}