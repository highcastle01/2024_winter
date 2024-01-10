#include<bits/stdc++.h>

using namespace std;

int dart1(double x, double y)
{
	double dist = x*x + y*y;
	double score = 0;

	if(dist <= 9)
	{
		score = 100;
	}
	else if(dist <= 36)
	{
		score = 80;
	}
	else if(dist <= 81)
	{
		score = 60;
	}
	else if(dist <= 144)
	{
		score = 40;
	}
	else if(dist <= 225)
	{
		score = 20;
	}
	else
	{
		score = 0;
	}

	return score;
}

int main(void)
{
	int t; cin >> t;

	while(t--)
	{
		int p1 = 0, p2 = 0;

		for(int i = 0; i < 3; i++)
		{
			double x, y; cin >> x >> y;
			p1 += dart1(x, y);
		}

		for(int i = 0; i < 3; i++)
		{
			double x, y; cin >> x >> y;
			p2 += dart1(x, y);
		}

		if(p1 == p2)
		{
			printf("SCORE: %d to %d, TIE.\n", p1, p2);
		}
		else if(p1 > p2)
		{
			printf("SCORE: %d to %d, PLAYER 1 WINS.\n", p1, p2);
		}
		else if(p1 < p2)
		{
			printf("SCORE: %d to %d, PLAYER 2 WINS.\n", p1, p2);
		}
	}

	return 0;
}